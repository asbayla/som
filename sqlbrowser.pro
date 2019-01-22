TEMPLATE        = app
TARGET          = sqlbrowser

QT              += sql widgets
requires(qtConfig(tableview))

HEADERS         = browser.h connectionwidget.h qsqlconnectiondialog.h \
    geojsongenerator.h \
    geojsonreader.h \
    geojsondbadapter.h \
    psqlquerybuilder.h \
    browser.h \
    connectionwidget.h \
    geojsondbadapter.h \
    geojsongenerator.h \
    geojsonreader.h \
    psqlquerybuilder.h \
    qsqlconnectiondialog.h \
    browser.h \
    connectionwidget.h \
    geojsondbadapter.h \
    geojsongenerator.h \
    geojsonreader.h \
    psqlquerybuilder.h \
    qsqlconnectiondialog.h \
    browser.h \
    connectionwidget.h \
    geojsondbadapter.h \
    geojsongenerator.h \
    geojsonreader.h \
    psqlquerybuilder.h \
    qsqlconnectiondialog.h \
    qtobjectvisitor.h \
    app.h
SOURCES         = main.cpp browser.cpp connectionwidget.cpp qsqlconnectiondialog.cpp \
    geojsongenerator.cpp \
    geojsonreader.cpp \
    geojsondbadapter.cpp \
    psqlquerybuilder.cpp \
    browser.cpp \
    connectionwidget.cpp \
    geojsondbadapter.cpp \
    geojsongenerator.cpp \
    geojsonreader.cpp \
    main.cpp \
    psqlquerybuilder.cpp \
    qsqlconnectiondialog.cpp \
    browser.cpp \
    connectionwidget.cpp \
    geojsondbadapter.cpp \
    geojsongenerator.cpp \
    geojsonreader.cpp \
    main.cpp \
    psqlquerybuilder.cpp \
    qsqlconnectiondialog.cpp \
    browser.cpp \
    connectionwidget.cpp \
    geojsondbadapter.cpp \
    geojsongenerator.cpp \
    geojsonreader.cpp \
    main.cpp \
    psqlquerybuilder.cpp \
    qsqlconnectiondialog.cpp \
    qtobjectvisitor.cpp \
    app.cpp

FORMS           = browserwidget.ui qsqlconnectiondialog.ui
build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}

# install
target.path = $$[QT_INSTALL_EXAMPLES]/sql/sqlbrowser
INSTALLS += target

DISTFILES += \
    data/geojson1.json
