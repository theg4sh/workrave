// INetwork.hh
//
// Copyright (C) 2007, 2008, 2009, 2012 Rob Caelers <robc@krandor.nl>
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef INETWORK_HH
#define INETWORK_HH

#include <list>
#include <map>
#include <string>

#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

#include "Types.hh"
#include "MessageParams.hh"
#include "MessageContext.hh"

namespace workrave
{
  namespace cloud
  {
    class INetwork
    {
    public:
      typedef boost::shared_ptr<INetwork> Ptr;
      typedef boost::signals2::signal<void(Message::Ptr, MessageContext::Ptr)> MessageSignal;
      
      virtual ~INetwork() {}
      
      virtual void send_message(Message::Ptr msg, MessageParams::Ptr param) = 0;
      virtual MessageSignal &signal_message(int domain, int id) = 0;
    };
  }
}


#endif // INETWORK_HH