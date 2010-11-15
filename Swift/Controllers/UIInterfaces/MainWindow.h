/*
 * Copyright (c) 2010 Kevin Smith
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#pragma once

#include "Swiften/Base/String.h"
#include "Swiften/JID/JID.h"
#include "Swiften/Elements/StatusShow.h"

#include "Swiften/Base/boost_bsignals.h"
#include <boost/shared_ptr.hpp>

namespace Swift {
	class Roster;

	class MainWindow {
		public:
			MainWindow(bool candelete = true) : canDelete_(candelete) {}
			virtual ~MainWindow() {};

			bool canDelete() const {
				return canDelete_;
			}

			virtual void setMyName(const String& name) = 0;
			virtual void setMyAvatarPath(const String& path) = 0;
			virtual void setMyStatusText(const String& status) = 0;
			virtual void setMyStatusType(StatusShow::Type type) = 0;
			/** Must be able to cope with NULL to clear the roster */
			virtual void setRosterModel(Roster* roster) = 0;
			virtual void setConnecting() = 0;
			
			boost::signal<void (StatusShow::Type, const String&)> onChangeStatusRequest;
			boost::signal<void ()> onSignOutRequest;

		private:
			bool canDelete_;
	};
}
