#include "mtmtts.h"
#include "globaldefine.h"

#include <QMutex>


MtmTTS::MtmTTS()
{
    // Initialize COM
#if defined Q_OS_WIN32
    pSpVoice = NULL;
#endif

    m_isOpened = false;
    LogInfo << GetVersion();
    IsPurgeBeforeSpeakThis = true;

#if defined Q_OS_WIN32
    CoInitialize(NULL);
#endif

    m_isOpened = init();
}

MtmTTS::~MtmTTS()
{
    //TTS关闭
#if defined Q_OS_WIN32
    CoUninitialize ();
#endif
}

bool MtmTTS::isOpened()
{
    return m_isOpened;
}

bool MtmTTS::init()
{
    bool bRet = true;
#if defined Q_OS_WIN32
    // Create the voice interface object
    if (FAILED(CoCreateInstance(CLSID_SpVoice, NULL,CLSCTX_INPROC_SERVER, IID_ISpVoice, (void **)&pSpVoice)))
    {
        LogInfo << "Get ISpVoice error";

        return false;
    }
    if (FAILED(SpEnumTokens(SPCAT_VOICES, L"Name=Girl XiaoKun", NULL, &cpEnum)))
    {
        LogInfo << "Get voice error";

        return false;
    }
    //Get the closest token
    if (FAILED(cpEnum->Next(1, &cpToken, NULL)))
    {
        LogInfo << "Get closest token error";

        return false;
    }
    //set the voice
    if (FAILED(pSpVoice->SetVoice( cpToken)))
    {
        LogInfo << "set voice error";

        return false;
    }
    bRet = true;
#else
    bRet = false;
#endif
    return bRet;

}

void MtmTTS::speak(QString text, bool IsPurgeBeforeSpeak, int speackflag)
{
    if(isOpened())
    {
#if defined Q_OS_WIN32
        if(pSpVoice)
        {
            SPVOICESTATUS es;
            LogInfo << "Begin to Speak Voice";
            // 耗时操作
            if (IsPurgeBeforeSpeakThis)
            {
                pSpVoice->GetStatus(&es, NULL );
                if (es.dwRunningState == SPRS_IS_SPEAKING)
                {
                    pSpVoice->Speak(NULL, SPF_PURGEBEFORESPEAK, 0);//结束语音,同时可以释放内存
                }
            }

            IsPurgeBeforeSpeakThis = IsPurgeBeforeSpeak;

            //设置朗读音量和速度
            pSpVoice->SetVolume(100); //设置音量，范围是 0 - 100
            pSpVoice->SetRate(0); //设置速度，范围是 -10 - 10

#ifdef UNICODE
            pSpVoice->Speak(text.toStdWString().c_str(), speackflag, 0);
#else
            pSpVoice->Speak(text.toStdString().c_str(), speackflag, 0);
#endif
            LogInfo << "End to Speak Voice";
        }
        else
        {
            LogInfo << "TTS Engine is not init";
        }
#endif
    }
    else
    {
        LogInfo << "TTS Engine is not opened";
    }
}

QString MtmTTS::GetVersion()
{
    return version;
}
