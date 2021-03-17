/*
 * ArduinoExt is a set of utility libraries for Arduino
 * Copyright (C) 2016, 2017 Andrey V. Skvortsov <starling13@mail.ru>
 *
 * This program is free software: is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.

 * ArduinoExt library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with Posixcpp library. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef CPS_HPP
#define CPS_HPP

#if __cplusplus <  201103L
#error This file requires C++11-able compiler
#endif

#define CPS_PACKED __attribute__ ((__packed__))

#define CPS_NOTCOPYABLE(ClassName)        \
private:                                  \
  ClassName(const ClassName&) = delete;   \
  ClassName(ClassName&&) = delete;        \
  ClassName &operator =(const ClassName&) = delete;

#define CPS_STATIC(ClassName)        \
private:                             \
  ClassName() = delete;

#define Package(ClassName) class ClassName final

#define CPS_PACKAGE(ClassName) \
  CPS_STATIC(ClassName) CPS_NOTCOPYABLE(ClassName)

#define Interface (ClassName) class ClassName

#define CPS_INTERFACE (ClassName) \
public: \
  virtual ~ClassName() = default; \
protected: \
  ClassName() = default; \
  CPS_NOTCOPYABLE(ClassName)

#endif //CPS_HPP

