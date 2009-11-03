//----------------------------------------------------------------------------//

/*
 * Copyright (c) 2009 Sony Pictures Imageworks
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.  Neither the name of Sony Pictures Imageworks nor the
 * names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//----------------------------------------------------------------------------//

/*! \file Log.h
  \brief Contains the Log class which can be used to redirect output to an
  arbitrary destination.  
*/

//----------------------------------------------------------------------------//

#ifndef _INCLUDED_Field3D_Log_H_
#define _INCLUDED_Field3D_Log_H_

//----------------------------------------------------------------------------//

#include <boost/lexical_cast.hpp>

//----------------------------------------------------------------------------//

#include "ns.h"

FIELD3D_NAMESPACE_OPEN

//----------------------------------------------------------------------------//
// Log namespace
//----------------------------------------------------------------------------//

//! Contains logging-related functions.
namespace Log {

  //! Used by the Log::print() call
  enum Severity {
    SevMessage, 
    SevWarning
  };

  //! Sends the string to the assigned output, prefixing the message with
  //! the severity
  void print(Severity severity, const std::string &message);

  //! Sends the string to the assigned output
  inline void print(const std::string &message)
  { print(SevMessage, message); }

} // namespace Log

//----------------------------------------------------------------------------//
// Logging-related functions
//----------------------------------------------------------------------------//

//! Converts any class with operator<< to a string using boost::lexical_cast
template <class T>
std::string str(const T& t);

//----------------------------------------------------------------------------//
// Implementations of templated functions
//----------------------------------------------------------------------------//

template <class T>
std::string str(const T& t)
{
  return boost::lexical_cast<std::string>(t);
}

//----------------------------------------------------------------------------//

FIELD3D_NAMESPACE_HEADER_CLOSE

//----------------------------------------------------------------------------//

#endif // Include guard
