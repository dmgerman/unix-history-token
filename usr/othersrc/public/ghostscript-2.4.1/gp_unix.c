begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gp_unix.c */
end_comment

begin_comment
comment|/* Unix-specific routines for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"memory_.h"
end_include

begin_include
include|#
directive|include
file|"string_.h"
end_include

begin_include
include|#
directive|include
file|"gx.h"
end_include

begin_include
include|#
directive|include
file|"gp.h"
end_include

begin_include
include|#
directive|include
file|"stat_.h"
end_include

begin_include
include|#
directive|include
file|"time_.h"
end_include

begin_comment
comment|/* popen isn't POSIX-standard, so we declare it here. */
end_comment

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pclose
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Do platform-dependent initialization. */
end_comment

begin_function
name|void
name|gp_init
parameter_list|()
block|{ }
end_function

begin_comment
comment|/* Do platform-dependent cleanup. */
end_comment

begin_function
name|void
name|gp_exit
parameter_list|()
block|{ }
end_function

begin_comment
comment|/* ------ Date and time ------ */
end_comment

begin_comment
comment|/* Read the current date (in days since Jan. 1, 1980) */
end_comment

begin_comment
comment|/* and time (in milliseconds since midnight). */
end_comment

begin_function
name|void
name|gp_get_clock
parameter_list|(
name|long
modifier|*
name|pdt
parameter_list|)
block|{
name|long
name|secs_since_1980
decl_stmt|;
name|struct
name|timeval
name|tp
decl_stmt|;
name|struct
name|timezone
name|tzp
decl_stmt|;
name|time_t
name|tsec
decl_stmt|;
name|struct
name|tm
modifier|*
name|tm
decl_stmt|,
modifier|*
name|localtime
argument_list|()
decl_stmt|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|tp
argument_list|,
operator|&
name|tzp
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"Ghostscript: gettimeofday failed:"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* tp.tv_sec is #secs since Jan 1, 1970 */
comment|/* subtract off number of seconds in 10 years */
comment|/* leap seconds are not accounted for */
name|secs_since_1980
operator|=
name|tp
operator|.
name|tv_sec
operator|-
call|(
name|long
call|)
argument_list|(
literal|60
operator|*
literal|60
operator|*
literal|24
operator|*
literal|365.25
operator|*
literal|10
argument_list|)
expr_stmt|;
comment|/* adjust for timezone */
name|secs_since_1980
operator|-=
operator|(
name|tzp
operator|.
name|tz_minuteswest
operator|*
literal|60
operator|)
expr_stmt|;
comment|/* adjust for daylight savings time - assume dst offset is 1 hour */
name|tsec
operator|=
name|tp
operator|.
name|tv_sec
expr_stmt|;
name|tm
operator|=
name|localtime
argument_list|(
operator|&
name|tsec
argument_list|)
expr_stmt|;
if|if
condition|(
name|tm
operator|->
name|tm_isdst
condition|)
name|secs_since_1980
operator|+=
operator|(
literal|60
operator|*
literal|60
operator|)
expr_stmt|;
comment|/* divide secs by #secs/day to get #days (integer division truncates) */
name|pdt
index|[
literal|0
index|]
operator|=
name|secs_since_1980
operator|/
operator|(
literal|60
operator|*
literal|60
operator|*
literal|24
operator|)
expr_stmt|;
comment|/* modulo + microsecs/1000 gives number of millisecs since midnight */
name|pdt
index|[
literal|1
index|]
operator|=
operator|(
name|secs_since_1980
operator|%
operator|(
literal|60
operator|*
literal|60
operator|*
literal|24
operator|)
operator|)
operator|*
literal|1000
operator|+
name|tp
operator|.
name|tv_usec
operator|/
literal|1000
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG_CLOCK
name|printf
argument_list|(
literal|"tp.tv_sec = %d  tp.tv_usec = %d  pdt[0] = %ld  pdt[1] = %ld\n"
argument_list|,
name|tp
operator|.
name|tv_sec
argument_list|,
name|tp
operator|.
name|tv_usec
argument_list|,
name|pdt
index|[
literal|0
index|]
argument_list|,
name|pdt
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ------ Screen management ------ */
end_comment

begin_comment
comment|/* Write a string to the console. */
end_comment

begin_function
name|void
name|gp_console_puts
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|uint
name|size
parameter_list|)
block|{
name|fwrite
argument_list|(
name|str
argument_list|,
literal|1
argument_list|,
name|size
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Make the console current on the screen. */
end_comment

begin_function
name|int
name|gp_make_console_current
parameter_list|(
name|struct
name|gx_device_s
modifier|*
name|dev
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Make the graphics current on the screen. */
end_comment

begin_function
name|int
name|gp_make_graphics_current
parameter_list|(
name|struct
name|gx_device_s
modifier|*
name|dev
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ------ Printer accessing ------ */
end_comment

begin_comment
comment|/* Open a connection to a printer.  A null file name means use the */
end_comment

begin_comment
comment|/* standard printer connected to the machine, if any. */
end_comment

begin_comment
comment|/* "|command" opens an output pipe. */
end_comment

begin_comment
comment|/* Return NULL if the connection could not be opened. */
end_comment

begin_function
name|FILE
modifier|*
name|gp_open_printer
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
block|{
return|return
operator|(
name|strlen
argument_list|(
name|fname
argument_list|)
operator|==
literal|0
condition|?
name|gp_open_scratch_file
argument_list|(
name|gp_scratch_file_name_prefix
argument_list|,
name|fname
argument_list|,
literal|"wb"
argument_list|)
else|:
name|fname
index|[
literal|0
index|]
operator|==
literal|'|'
condition|?
name|popen
argument_list|(
name|fname
operator|+
literal|1
argument_list|,
literal|"wb"
argument_list|)
else|:
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"wb"
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Close the connection to the printer. */
end_comment

begin_function
name|void
name|gp_close_printer
parameter_list|(
name|FILE
modifier|*
name|pfile
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
if|if
condition|(
name|fname
index|[
literal|0
index|]
operator|==
literal|'|'
condition|)
name|pclose
argument_list|(
name|pfile
argument_list|)
expr_stmt|;
else|else
name|fclose
argument_list|(
name|pfile
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------ File names ------ */
end_comment

begin_comment
comment|/* Define the character used for separating file names in a list. */
end_comment

begin_decl_stmt
specifier|const
name|char
name|gp_file_name_list_separator
init|=
literal|':'
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the default scratch file name prefix. */
end_comment

begin_decl_stmt
specifier|const
name|char
name|gp_scratch_file_name_prefix
index|[]
init|=
literal|"/tmp/gs_"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define whether case is insignificant in file names. */
end_comment

begin_decl_stmt
specifier|const
name|int
name|gp_file_names_ignore_case
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create and open a scratch file with a given name prefix. */
end_comment

begin_comment
comment|/* Write the actual file name at fname. */
end_comment

begin_function
name|FILE
modifier|*
name|gp_open_scratch_file
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
name|strcpy
argument_list|(
name|fname
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|fname
argument_list|,
literal|"XXXXXX"
argument_list|)
expr_stmt|;
name|mktemp
argument_list|(
name|fname
argument_list|)
expr_stmt|;
return|return
name|fopen
argument_list|(
name|fname
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Answer whether a file name contains a directory/device specification, */
end_comment

begin_comment
comment|/* i.e. is absolute (not directory- or device-relative). */
end_comment

begin_function
name|int
name|gp_file_name_is_absolute
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|uint
name|len
parameter_list|)
block|{
comment|/* A file name is absolute if it starts with a /. */
return|return
operator|(
name|len
operator|>=
literal|1
operator|&&
operator|*
name|fname
operator|==
literal|'/'
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Answer the string to be used for combining a directory/device prefix */
end_comment

begin_comment
comment|/* with a base file name.  The file name is known to not be absolute. */
end_comment

begin_function
name|char
modifier|*
name|gp_file_name_concat_string
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
name|uint
name|plen
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|uint
name|len
parameter_list|)
block|{
if|if
condition|(
name|plen
operator|>
literal|0
operator|&&
name|prefix
index|[
name|plen
operator|-
literal|1
index|]
operator|==
literal|'/'
condition|)
return|return
literal|""
return|;
return|return
literal|"/"
return|;
block|}
end_function

begin_comment
comment|/* ------ File operations ------ */
end_comment

begin_comment
comment|/* If the file given by fname exists, fill in its status and return 1; */
end_comment

begin_comment
comment|/* otherwise return 0. */
end_comment

begin_function
name|int
name|gp_file_status
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|file_status
modifier|*
name|pstatus
parameter_list|)
block|{
name|struct
name|stat
name|sbuf
decl_stmt|;
comment|/* The RS/6000 prototype for stat doesn't include const, */
comment|/* so we have to explicitly remove the const modifier. */
if|if
condition|(
name|stat
argument_list|(
operator|(
name|char
operator|*
operator|)
name|fname
argument_list|,
operator|&
name|sbuf
argument_list|)
operator|<
literal|0
condition|)
return|return
literal|0
return|;
name|pstatus
operator|->
name|size_pages
operator|=
name|stat_blocks
argument_list|(
operator|&
name|sbuf
argument_list|)
expr_stmt|;
comment|/* st_blocks is */
comment|/* missing on some systems, */
comment|/* see stat_.h */
name|pstatus
operator|->
name|size_bytes
operator|=
name|sbuf
operator|.
name|st_size
expr_stmt|;
name|pstatus
operator|->
name|time_referenced
operator|=
name|sbuf
operator|.
name|st_mtime
expr_stmt|;
name|pstatus
operator|->
name|time_created
operator|=
name|sbuf
operator|.
name|st_ctime
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* ------ File enumeration ------ */
end_comment

begin_comment
comment|/****** THIS IS NOT SUPPORTED ON UNIX SYSTEMS. ******/
end_comment

begin_comment
comment|/* Amazingly enough, there is no standard Unix library routine */
end_comment

begin_comment
comment|/* for enumerating the files matching a pattern, */
end_comment

begin_comment
comment|/* or even for enumerating (conveniently) the files in a directory. */
end_comment

begin_struct
struct|struct
name|file_enum_s
block|{
name|char
modifier|*
name|pattern
decl_stmt|;
name|int
name|first_time
decl_stmt|;
name|gs_memory_procs
name|mprocs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize an enumeration.  NEEDS WORK ON HANDLING * ? \. */
end_comment

begin_function
name|file_enum
modifier|*
name|gp_enumerate_files_init
parameter_list|(
specifier|const
name|char
modifier|*
name|pat
parameter_list|,
name|uint
name|patlen
parameter_list|,
name|proc_alloc_t
name|palloc
parameter_list|,
name|proc_free_t
name|pfree
parameter_list|)
block|{
name|file_enum
modifier|*
name|pfen
init|=
operator|(
name|file_enum
operator|*
operator|)
call|(
modifier|*
name|palloc
call|)
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|file_enum
argument_list|)
argument_list|,
literal|"gp_enumerate_files"
argument_list|)
decl_stmt|;
name|char
modifier|*
name|pattern
decl_stmt|;
if|if
condition|(
name|pfen
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|pattern
operator|=
call|(
modifier|*
name|palloc
call|)
argument_list|(
name|patlen
operator|+
literal|1
argument_list|,
literal|1
argument_list|,
literal|"gp_enumerate_files(pattern)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|pattern
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|memcpy
argument_list|(
name|pattern
argument_list|,
name|pat
argument_list|,
name|patlen
argument_list|)
expr_stmt|;
name|pattern
index|[
name|patlen
index|]
operator|=
literal|0
expr_stmt|;
name|pfen
operator|->
name|pattern
operator|=
name|pattern
expr_stmt|;
name|pfen
operator|->
name|mprocs
operator|.
name|alloc
operator|=
name|palloc
expr_stmt|;
name|pfen
operator|->
name|mprocs
operator|.
name|free
operator|=
name|pfree
expr_stmt|;
name|pfen
operator|->
name|first_time
operator|=
literal|1
expr_stmt|;
return|return
name|pfen
return|;
block|}
end_function

begin_comment
comment|/* Enumerate the next file. */
end_comment

begin_function
name|uint
name|gp_enumerate_files_next
parameter_list|(
name|file_enum
modifier|*
name|pfen
parameter_list|,
name|char
modifier|*
name|ptr
parameter_list|,
name|uint
name|maxlen
parameter_list|)
block|{
if|if
condition|(
name|pfen
operator|->
name|first_time
condition|)
block|{
name|pfen
operator|->
name|first_time
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Clean up the file enumeration. */
end_comment

begin_function
name|void
name|gp_enumerate_files_close
parameter_list|(
name|file_enum
modifier|*
name|pfen
parameter_list|)
block|{
name|proc_free_t
name|pfree
init|=
name|pfen
operator|->
name|mprocs
operator|.
name|free
decl_stmt|;
call|(
modifier|*
name|pfree
call|)
argument_list|(
name|pfen
operator|->
name|pattern
argument_list|,
name|strlen
argument_list|(
name|pfen
operator|->
name|pattern
argument_list|)
operator|+
literal|1
argument_list|,
literal|1
argument_list|,
literal|"gp_enumerate_files_close(pattern)"
argument_list|)
expr_stmt|;
call|(
modifier|*
name|pfree
call|)
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pfen
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|file_enum
argument_list|)
argument_list|,
literal|"gp_enumerate_files_close"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

