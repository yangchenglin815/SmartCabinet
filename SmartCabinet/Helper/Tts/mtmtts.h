/**
 * @file mtmtts.h
 * @brief 语音播报头文件
 * @details 用于语音播放指定文本
 * @warning 目前主要为Windows系统、linux未完全兼容
 * @todo 基于微软SAPI，linux暂不可用
 * @author 郭星
 * @version MtmTTS 1.0.2.180814
 * @date 2017-09-14
 */
#ifndef MTMTTS_H
#define MTMTTS_H

#include <QtCore/qglobal.h>

#if defined Q_OS_WIN32
#include <sapi.h>
#include <sphelper.h>
#include <atlcom.h>
#endif

#include <QString>

//#if defined(MtmTTS_STATICLIB)
//#define MTMTTSSHARED_EXPORT
//#else
//#if defined(MTMTTS_LIBRARY)
//#define MTMTTSSHARED_EXPORT Q_DECL_EXPORT
//#else
//#define MTMTTSSHARED_EXPORT Q_DECL_IMPORT
//#endif
//#endif

/**
 * @brief The MtmTTS class 语音播报类库
 * @details 基于微软SAPI，linux暂不可用
 */
class MtmTTS
{
public:
    MtmTTS();
    ~MtmTTS();

    /**
     * @brief isOpened 是否打开语音
     * @return 返回是否打开语音
     */
    bool isOpened();

    //text需要播放的内容
    //IsPurgeBeforeSpeak播放下一段语音时是否清除上一段语音，TRUE为清除
    //speackflag播放语音的方式 SPF_DEFAULT 同步播放 SPF_ASYNC异步播放
    /**
     * @brief speak 播放指定文本语音
     * @param text 文本内容
     * @param IsPurgeBeforeSpeak 播放下一段语音时是否清除上一段语音 true:清除 false:不清除
     * @param speackflag 播放语音的方式 0:同步 1:异步
     */
    void speak(QString text, bool IsPurgeBeforeSpeak = true, int speackflag = 1 /*SPF_ASYNC	= ( 1L << 0 )*/);

    /**
     * @brief GetVersion 版本号
     * @return
     */
    QString GetVersion();

private:
    bool init();

private:
#if defined Q_OS_WIN32
    ISpVoice * pSpVoice;
    CComPtr<IEnumSpObjectTokens> cpEnum;
    CComPtr<ISpObjectToken> cpToken;
#endif

    bool IsPurgeBeforeSpeakThis;//是否打断本次语音

    bool m_isOpened;

    const QString version = "MtmTTS 1.0.2.180814";
};


#endif // MTMTTS_H
