// Copyright (C) 2017 go-nebulas authors
//
// This file is part of the go-nebulas library.
//
// the go-nebulas library is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// the go-nebulas library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with the go-nebulas library.  If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef _NEBULAS_NV_V8_ENGINE_H_
#define _NEBULAS_NV_V8_ENGINE_H_

#if BUILDING_DLL
#define EXPORT __attribute__((__visibility__("default")))
#else
#define EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum LogLevel {
  DEBUG = 1,
  WARN = 2,
  INFO = 3,
  ERROR = 4,
};

typedef void (*LogFunc)(int level, const char *msg);
EXPORT const char *GetLogLevelText(int level);
EXPORT void SetLogFunc(LogFunc f);

typedef struct V8Engine {
  void *isolate;
  void *allocator;
} V8Engine;

EXPORT void Initialize(LogFunc logFunc);
EXPORT void Dispose();

EXPORT V8Engine *CreateEngine();
EXPORT int RunScriptSource(V8Engine *e, const char *data);
EXPORT void DeleteEngine(V8Engine *e);

#ifdef __cplusplus
}
#endif

#endif
