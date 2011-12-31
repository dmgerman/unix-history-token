begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright (c) 2006, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|// All functions here are thread-hostile due to file caching unless
end_comment

begin_comment
comment|// commented otherwise.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYSINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYSINFO_H_
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN32__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|// for DWORD
end_comment

begin_include
include|#
directive|include
file|<TlHelp32.h>
end_include

begin_comment
comment|// for CreateToolhelp32Snapshot
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|// for pid_t
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|// for PATH_MAX
end_comment

begin_include
include|#
directive|include
file|"basictypes.h"
end_include

begin_comment
comment|// This getenv function is safe to call before the C runtime is initialized.
end_comment

begin_comment
comment|// On Windows, it utilizes GetEnvironmentVariable() and on unix it uses
end_comment

begin_comment
comment|// /proc/self/environ instead calling getenv().  It's intended to be used in
end_comment

begin_comment
comment|// routines that run before main(), when the state required for getenv() may
end_comment

begin_comment
comment|// not be set up yet.  In particular, errno isn't set up until relatively late
end_comment

begin_comment
comment|// (after the pthreads library has a chance to make it threadsafe), and
end_comment

begin_comment
comment|// getenv() doesn't work until then.
end_comment

begin_comment
comment|// On some platforms, this call will utilize the same, static buffer for
end_comment

begin_comment
comment|// repeated GetenvBeforeMain() calls. Callers should not expect pointers from
end_comment

begin_comment
comment|// this routine to be long lived.
end_comment

begin_comment
comment|// Note that on unix, /proc only has the environment at the time the
end_comment

begin_comment
comment|// application was started, so this routine ignores setenv() calls/etc.  Also
end_comment

begin_comment
comment|// note it only reads the first 16K of the environment.
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|GetenvBeforeMain
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// This takes as an argument an environment-variable name (like
end_comment

begin_comment
comment|// CPUPROFILE) whose value is supposed to be a file-path, and sets
end_comment

begin_comment
comment|// path to that path, and returns true.  Non-trivial for surprising
end_comment

begin_comment
comment|// reasons, as documented in sysinfo.cc.  path must have space PATH_MAX.
end_comment

begin_function_decl
specifier|extern
name|bool
name|GetUniquePathFromEnv
parameter_list|(
specifier|const
name|char
modifier|*
name|env_name
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|NumCPUs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// processor cycles per second of each processor.  Thread-safe.
end_comment

begin_function_decl
specifier|extern
name|double
name|CyclesPerSecond
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//  Return true if we're running POSIX (e.g., NPTL on Linux) threads,
end_comment

begin_comment
comment|//  as opposed to a non-POSIX thread libary.  The thing that we care
end_comment

begin_comment
comment|//  about is whether a thread's pid is the same as the thread that
end_comment

begin_comment
comment|//  spawned it.  If so, this function returns true.
end_comment

begin_comment
comment|//  Thread-safe.
end_comment

begin_comment
comment|//  Note: We consider false negatives to be OK.
end_comment

begin_function_decl
name|bool
name|HasPosixThreads
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|SWIG
end_ifndef

begin_comment
comment|// SWIG doesn't like struct Buffer and variable arguments.
end_comment

begin_comment
comment|// A ProcMapsIterator abstracts access to /proc/maps for a given
end_comment

begin_comment
comment|// process. Needs to be stack-allocatable and avoid using stdio/malloc
end_comment

begin_comment
comment|// so it can be used in the google stack dumper, heap-profiler, etc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// On Windows and Mac OS X, this iterator iterates *only* over DLLs
end_comment

begin_comment
comment|// mapped into this process space.  For Linux, FreeBSD, and Solaris,
end_comment

begin_comment
comment|// it iterates over *all* mapped memory regions, including anonymous
end_comment

begin_comment
comment|// mmaps.  For other O/Ss, it is unlikely to work at all, and Valid()
end_comment

begin_comment
comment|// will always return false.  Also note: this routine only works on
end_comment

begin_comment
comment|// FreeBSD if procfs is mounted: make sure this is in your /etc/fstab:
end_comment

begin_comment
comment|//    proc            /proc   procfs  rw 0 0
end_comment

begin_decl_stmt
name|class
name|ProcMapsIterator
block|{
name|public
label|:
struct|struct
name|Buffer
block|{
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|// FreeBSD requires us to read all of the maps file at once, so
comment|// we have to make a buffer that's "always" big enough
specifier|static
specifier|const
name|size_t
name|kBufSize
init|=
literal|102400
decl_stmt|;
else|#
directive|else
comment|// a one-line buffer is good enough
specifier|static
specifier|const
name|size_t
name|kBufSize
init|=
name|PATH_MAX
operator|+
literal|1024
decl_stmt|;
endif|#
directive|endif
name|char
name|buf_
index|[
name|kBufSize
index|]
decl_stmt|;
block|}
struct|;
comment|// Create a new iterator for the specified pid.  pid can be 0 for "self".
name|explicit
name|ProcMapsIterator
parameter_list|(
name|pid_t
name|pid
parameter_list|)
function_decl|;
comment|// Create an iterator with specified storage (for use in signal
comment|// handler). "buffer" should point to a ProcMapsIterator::Buffer
comment|// buffer can be NULL in which case a bufer will be allocated.
name|ProcMapsIterator
argument_list|(
argument|pid_t pid
argument_list|,
argument|Buffer *buffer
argument_list|)
empty_stmt|;
comment|// Iterate through maps_backing instead of maps if use_maps_backing
comment|// is true.  Otherwise the same as above.  buffer can be NULL and
comment|// it will allocate a buffer itself.
name|ProcMapsIterator
argument_list|(
argument|pid_t pid
argument_list|,
argument|Buffer *buffer
argument_list|,
argument|bool use_maps_backing
argument_list|)
empty_stmt|;
comment|// Returns true if the iterator successfully initialized;
name|bool
name|Valid
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns a pointer to the most recently parsed line. Only valid
comment|// after Next() returns true, and until the iterator is destroyed or
comment|// Next() is called again.  This may give strange results on non-Linux
comment|// systems.  Prefer FormatLine() if that may be a concern.
specifier|const
name|char
operator|*
name|CurrentLine
argument_list|()
specifier|const
block|{
return|return
name|stext_
return|;
block|}
comment|// Writes the "canonical" form of the /proc/xxx/maps info for a single
comment|// line to the passed-in buffer. Returns the number of bytes written,
comment|// or 0 if it was not able to write the complete line.  (To guarantee
comment|// success, buffer should have size at least Buffer::kBufSize.)
comment|// Takes as arguments values set via a call to Next().  The
comment|// "canonical" form of the line (taken from linux's /proc/xxx/maps):
comment|//<start_addr(hex)>-<end_addr(hex)><perms(rwxp)><offset(hex)>   +
comment|//<major_dev(hex)>:<minor_dev(hex)><inode><filename> Note: the
comment|// eg
comment|//    08048000-0804c000 r-xp 00000000 03:01 3793678    /bin/cat
comment|// If you don't have the dev_t (dev), feel free to pass in 0.
comment|// (Next() doesn't return a dev_t, though NextExt does.)
comment|//
comment|// Note: if filename and flags were obtained via a call to Next(),
comment|// then the output of this function is only valid if Next() returned
comment|// true, and only until the iterator is destroyed or Next() is
comment|// called again.  (Since filename, at least, points into CurrentLine.)
specifier|static
name|int
name|FormatLine
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|bufsize
parameter_list|,
name|uint64
name|start
parameter_list|,
name|uint64
name|end
parameter_list|,
specifier|const
name|char
modifier|*
name|flags
parameter_list|,
name|uint64
name|offset
parameter_list|,
name|int64
name|inode
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|dev_t
name|dev
parameter_list|)
function_decl|;
comment|// Find the next entry in /proc/maps; return true if found or false
comment|// if at the end of the file.
comment|//
comment|// Any of the result pointers can be NULL if you're not interested
comment|// in those values.
comment|//
comment|// If "flags" and "filename" are passed, they end up pointing to
comment|// storage within the ProcMapsIterator that is valid only until the
comment|// iterator is destroyed or Next() is called again. The caller may
comment|// modify the contents of these strings (up as far as the first NUL,
comment|// and only until the subsequent call to Next()) if desired.
comment|// The offsets are all uint64 in order to handle the case of a
comment|// 32-bit process running on a 64-bit kernel
comment|//
comment|// IMPORTANT NOTE: see top-of-class notes for details about what
comment|// mapped regions Next() iterates over, depending on O/S.
comment|// TODO(csilvers): make flags and filename const.
name|bool
name|Next
parameter_list|(
name|uint64
modifier|*
name|start
parameter_list|,
name|uint64
modifier|*
name|end
parameter_list|,
name|char
modifier|*
modifier|*
name|flags
parameter_list|,
name|uint64
modifier|*
name|offset
parameter_list|,
name|int64
modifier|*
name|inode
parameter_list|,
name|char
modifier|*
modifier|*
name|filename
parameter_list|)
function_decl|;
name|bool
name|NextExt
parameter_list|(
name|uint64
modifier|*
name|start
parameter_list|,
name|uint64
modifier|*
name|end
parameter_list|,
name|char
modifier|*
modifier|*
name|flags
parameter_list|,
name|uint64
modifier|*
name|offset
parameter_list|,
name|int64
modifier|*
name|inode
parameter_list|,
name|char
modifier|*
modifier|*
name|filename
parameter_list|,
name|uint64
modifier|*
name|file_mapping
parameter_list|,
name|uint64
modifier|*
name|file_pages
parameter_list|,
name|uint64
modifier|*
name|anon_mapping
parameter_list|,
name|uint64
modifier|*
name|anon_pages
parameter_list|,
name|dev_t
modifier|*
name|dev
parameter_list|)
function_decl|;
operator|~
name|ProcMapsIterator
argument_list|()
expr_stmt|;
name|private
label|:
name|void
name|Init
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|Buffer
modifier|*
name|buffer
parameter_list|,
name|bool
name|use_maps_backing
parameter_list|)
function_decl|;
name|char
modifier|*
name|ibuf_
decl_stmt|;
comment|// input buffer
name|char
modifier|*
name|stext_
decl_stmt|;
comment|// start of text
name|char
modifier|*
name|etext_
decl_stmt|;
comment|// end of text
name|char
modifier|*
name|nextline_
decl_stmt|;
comment|// start of next line
name|char
modifier|*
name|ebuf_
decl_stmt|;
comment|// end of buffer (1 char for a nul)
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN32__
argument_list|)
operator|)
name|HANDLE
name|snapshot_
decl_stmt|;
comment|// filehandle on dll info
comment|// In a change from the usual W-A pattern, there is no A variant of
comment|// MODULEENTRY32.  Tlhelp32.h #defines the W variant, but not the A.
comment|// We want the original A variants, and this #undef is the only
comment|// way I see to get them.  Redefining it when we're done prevents us
comment|// from affecting other .cc files.
ifdef|#
directive|ifdef
name|MODULEENTRY32
comment|// Alias of W
undef|#
directive|undef
name|MODULEENTRY32
name|MODULEENTRY32
name|module_
decl_stmt|;
comment|// info about current dll (and dll iterator)
define|#
directive|define
name|MODULEENTRY32
value|MODULEENTRY32W
else|#
directive|else
comment|// It's the ascii, the one we want.
name|MODULEENTRY32
name|module_
decl_stmt|;
comment|// info about current dll (and dll iterator)
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|__MACH__
argument_list|)
name|int
name|current_image_
decl_stmt|;
comment|// dll's are called "images" in macos parlance
name|int
name|current_load_cmd_
decl_stmt|;
comment|// the segment of this dll we're examining
elif|#
directive|elif
name|defined
argument_list|(
name|__sun__
argument_list|)
comment|// Solaris
name|int
name|fd_
decl_stmt|;
name|char
name|current_filename_
index|[
name|PATH_MAX
index|]
decl_stmt|;
else|#
directive|else
name|int
name|fd_
decl_stmt|;
comment|// filehandle on /proc/*/maps
endif|#
directive|endif
name|pid_t
name|pid_
decl_stmt|;
name|char
name|flags_
index|[
literal|10
index|]
decl_stmt|;
name|Buffer
modifier|*
name|dynamic_buffer_
decl_stmt|;
comment|// dynamically-allocated Buffer
name|bool
name|using_maps_backing_
decl_stmt|;
comment|// true if we are looking at maps_backing instead of maps.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef SWIG */
end_comment

begin_comment
comment|// Helper routines
end_comment

begin_typedef
typedef|typedef
name|int
name|RawFD
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|RawFD
name|kIllegalRawFD
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// what open returns if it fails
end_comment

begin_function_decl
name|RawFD
name|RawOpenForWriting
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// uses default permissions
end_comment

begin_function_decl
name|void
name|RawWrite
parameter_list|(
name|RawFD
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RawClose
parameter_list|(
name|RawFD
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|FillProcSelfMaps
parameter_list|(
name|char
name|buf
index|[]
parameter_list|,
name|int
name|size
parameter_list|,
name|bool
modifier|*
name|wrote_all
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DumpProcSelfMaps
parameter_list|(
name|RawFD
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _SYSINFO_H_ */
end_comment

end_unit

