/* Teensy Logger library code is placed under the MIT license
 * Copyright (c) 2020 Frank Bösing
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
 
#ifndef _teensy_logger_h
#define _teensy_logger_h

//#define LOGTIMESTAMP
//#define LOGPRINTLEVEL

#ifndef LOGDEVICE
#define LOGDEVICE    Serial
#endif

#ifndef LOG_LEVEL
#define LOG_LEVEL   -1
#endif

#define LOG_NONE    -1
#define LOG_ERROR    0
#define LOG_WARN     1
#define LOG_INFO     2
#define LOG_DEBUG    3
#define LOG_VERBOSE  4

const __attribute__((unused))  char* __log_str[][5] = {"ERROR", "WARNING", "INFO", "DEBUG", "VERBOSE"};
const __attribute__((unused))  unsigned long __tLOG = millis();

#define __MSECS_PER_MIN  (60000UL)
#define __MSECS_PER_HOUR (3600000UL)
#define __MSECS_PER_DAY  (__MSECS_PER_HOUR * 24UL)

#ifdef LOG_LEVEL
void _LOGMETA(const int level)
{
#if defined(LOGTIMESTAMP)
  unsigned long m = millis() - __tLOG;
  LOGDEVICE.printf("%02lu:%02lu:%02lu.%03lu ",
                (m % __MSECS_PER_DAY) / __MSECS_PER_HOUR,
                (m / __MSECS_PER_MIN) % __MSECS_PER_MIN,
                (m % __MSECS_PER_MIN) / 1000UL,
                m % 1000UL);
#endif

#ifdef LOGPRINTLEVEL
  LOGDEVICE.printf("[%s] ", __log_str[0][level]);
#endif
}
#endif

#ifdef LOG_LEVEL
#define _LOG_GENERIC(level, format, ... ) { \
    if (level <= LOG_LEVEL) { \
      _LOGMETA(level); \
      LOGDEVICE.printf(format "\n", ##__VA_ARGS__); \
    } \
  }
#else
#define _LOG_GENERIC(level, format, ... ) {;}
#endif

#define LOGE(format, ... ) _LOG_GENERIC(LOG_ERROR, format, ##__VA_ARGS__)
#define LOGW(format, ... ) _LOG_GENERIC(LOG_WARN, format, ##__VA_ARGS__)
#define LOGI(format, ... ) _LOG_GENERIC(LOG_INFO, format, ##__VA_ARGS__)
#define LOGD(format, ... ) _LOG_GENERIC(LOG_DEBUG, format, ##__VA_ARGS__)
#define LOGV(format, ... ) _LOG_GENERIC(LOG_VERBOSE, format, ##__VA_ARGS__)

#endif
