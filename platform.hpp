#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#ifdef _WIN32

#include <io.h>
#include <direct.h>
#include <BaseTsd.h>

typedef SSIZE_T ssize_t;

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

// Map POSIX names to Windows equivalents
#define close _close
#define write _write
#define read _read
#define lseek _lseek
#define fdopen _fdopen
#define fileno _fileno
#define ftruncate _chsize
#define unlink _unlink
#define stat _stat

// mkdir on Windows takes only one argument
#define mkdir(path, mode) _mkdir(path)

#else

#include <unistd.h>

#endif

#endif
