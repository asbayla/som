#include "app.h"

#include <QDir>
#include <QTemporaryFile>

#include "qtobjectvisitor.h"

App::App()
{

}

void App::convertJsonToQt()
{
    const QString result = tr("Converting ... ");
    setResult(result);
    setRhsTitleAndText(mRhsDefaultTitle, "");
    setQtData (QVariant());

    //        JsonDataAccess jda;
    //        QVariant qtData = jda.loadFromBuffer(mJsonData);
    //        if (jda.hasError()) {
    //            const DataAccessError err = jda.error();
    //            const QString errorMsg = tr("Error converting JSON data: %1").arg(err.errorMessage());
    //            setResultAndState(errorMsg, JsonLoaded);
    //        } else {
    //            setQtData(qtData);
    //            const QtObjectVisitor fmt;
    //            setRhsTitleAndText(tr("Qt Data from JSON"), fmt.asString(qtData));
    //            setResultAndState(result + tr("Success"), QtDisplayed);
    //        }
}


void App::loadJsonFileRaw(const QString& resultMsg, QFile& jsonFile)
{
    if (!jsonFile.open(QFile::ReadOnly)) {
        const QString msg = tr("Failed to open JSON file: %1").arg(jsonFile.fileName());
        setJsonData (QString());
        setResultAndState(msg, Init);
        return;
    }

    const QString doc = QString::fromUtf8(jsonFile.readAll());
    setJsonData(doc);
    setResultAndState(resultMsg + tr("Success"), JsonLoaded);
}



void App::convertQtToJson()
{
    const QString result = tr("Converting ... ");
    setResult(result);
    setRhsTitleAndText(mRhsDefaultTitle, "");

    QString jsonBuffer;
    //        JsonDataAccess jda;
    //        jda.saveToBuffer(mQtData, &jsonBuffer);
    //        if (jda.hasError()) {
    //            const DataAccessError err = jda.error();
    //            const QString errorMsg = tr("Error converting Qt data to JSON: %1").arg(err.errorMessage());
    //            setResultAndState(errorMsg, QtDisplayed);
    //        } else {
    //            setRhsTitleAndText(tr("JSON Data from Qt"), jsonBuffer);
    //            setResultAndState(result + tr("Success"), ReadyToWrite);
    //        }
}

void App::writeToJsonFileAndReload()
{
    const QString result = tr("Writing file ... ");
    setResult(result);

    const QDir home = QDir::home();
    QTemporaryFile file(home.absoluteFilePath("XXXXXX.json"));
    //       if (file.open()) {
    //           JsonDataAccess jda(&file);
    //           jda.save(mQtData, &file);
    //           if (jda.hasError()) {
    //               const DataAccessError err = jda.error();
    //               const QString errorMsg = tr("Error writing data to JSON file: %1").arg(err.errorMessage());
    //               setResultAndState(errorMsg, ReadyToWrite);
    //           } else {
    //               file.close();
    //               loadJsonFileRaw(tr("Reloading new JSON file ... "), file);
    //           }
    //       }
}

void App::setJsonData(const QString& data)
{
    if (mJsonData == data)
        return;

    mJsonData = data;
    emit jsonDataChanged(data);
}

QString App::rhsTitle() const
{
    return mRhsTitle;
}

void App::setRhsTitle(const QString& title)
{
    if (mRhsTitle == title)
        return;

    mRhsTitle = title;
    emit rhsTitleChanged(title);
}

QString App::rhsText() const
{
    return mRhsText;
}

void App::setRhsText(const QString& text)
{
    if (mRhsText == text)
        return;

    mRhsText = text;
    emit rhsTextChanged(text);
}

QString App::result() const
{
    return mResult;
}

void App::setResult(const QString& result)
{
    if (mResult == result)
        return;

    mResult = result;
    emit resultChanged(result);
}

App::State App::state() const
{
    return mState;
}

void App::setState(const State state)
{
    if (mState == state)
        return;

    mState = state;
    emit stateChanged(state);
}
void App::setQtData(const QVariant& data)
{
    mQtData = data;
}

void App::setResultAndState(const QString& result, State newState)
{
    setResult(result);
    setState(newState);
}



void App::setRhsTitleAndText(const QString& title, const QString& text)
{
    setRhsTitle(title);
    setRhsText(text);
}

QString App::jsonData() const
{
    return mJsonData;
}

void App::updateJsonDataFromQml(const QString &data)
{
    mJsonData = data;
}

void App::loadOriginalJson()
{
    const QString result = tr("Loading ... ");
    setResult(result);
    setRhsTitleAndText(mRhsDefaultTitle, "");
    setQtData(QVariant());

//    QFile jsonFile(assetPath("snippet.json"));
//    loadJsonFileRaw(result, jsonFile);
}

