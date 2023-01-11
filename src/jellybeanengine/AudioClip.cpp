#include "AudioClip.h"
#include "stb_vorbis.h"
#include "Exception.h"

namespace JellyBean_Engine
{
	/*
	*	This is where the initialisation for the Audio Clip comes in,
	*	once the source has been sorted. We load in the path using the
	*	loadOgg function.
	*/

	void AudioClip::onInit()
	{
		format = 0;
		freq = 0;

		alGenBuffers(1, &id);

		loadOgg(getPath() + ".ogg", bufferData, format, freq);

		alBufferData(id, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);

	}

	/*
	*	The loadOgg path function utilises stb_vorbis in loading audio
	*	files into OpenGL. We also cut out the need for telling our
	*	function what file extension we need when writing the path, 
	*	as the function has the ability to say what extension to look
	*	for.
	*/

	void AudioClip::loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(fileName.c_str(), &channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw Exception("Failed to open file '" + fileName + "' for decoding");
		}

		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}

		else
		{
			format = AL_FORMAT_STEREO16;
		}

		freq = sampleRate;

		buffer.resize(samples * 2);
		memcpy(&buffer.at(0), output, buffer.size());

		free(output);
	}
}