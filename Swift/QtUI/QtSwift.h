#ifndef SWIFT_QtSwift_H
#define SWIFT_QtSwift_H

#include "Swiften/Base/String.h"
#include "Swiften/EventLoop/Qt/QtEventLoop.h"
#include "QtLoginWindowFactory.h"
#include "QtMainWindowFactory.h"
#include "QtChatWindowFactory.h"
#include "QtSettingsProvider.h"
#include "QtIdleDetector.h"

class QSplitter;

namespace Swift {
	class Application;
	class MainController;
	class QtChatWindowFactory;
	class QtMainWindowFactory;
	class QtLoginWindowFactory;
	class QtTreeWidgetFactory;
	class QtSystemTray;
	class QtSoundPlayer;
	
	class QtSwift : public QObject {
		Q_OBJECT
		public:
			QtSwift(bool netbookMode);
			~QtSwift();
		private:
			MainController *mainController_;
			QtTreeWidgetFactory *treeWidgetFactory_;
			QtChatWindowFactory *chatWindowFactory_;
			QtMainWindowFactory *rosterWindowFactory_;
			QtLoginWindowFactory *loginWindowFactory_;
			QtEventLoop clientMainThreadCaller_;
			QtSettingsProvider *settings_;
			QtSystemTray* systemTray_;
			QSplitter* splitter_;
			QtSoundPlayer* soundPlayer_;
			QtIdleDetector* idleDetector_;
			Application* application_;
	};
}

#endif
