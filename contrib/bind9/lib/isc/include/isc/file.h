begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009, 2011-2014  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_FILE_H
value|1
end_define

begin_comment
comment|/*! \file isc/file.h */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/stat.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_file_settime
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|isc_time_t
modifier|*
name|time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_file_mode
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|mode_t
modifier|*
name|modep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_file_getmodtime
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|isc_time_t
modifier|*
name|time
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Get the time of last modification of a file.  *  * Notes:  *\li	The time that is set is relative to the (OS-specific) epoch, as are  *	all isc_time_t structures.  *  * Requires:  *\li	file != NULL.  *\li	time != NULL.  *  * Ensures:  *\li	If the file could not be accessed, 'time' is unchanged.  *  * Returns:  *\li	#ISC_R_SUCCESS  *		Success.  *\li	#ISC_R_NOTFOUND  *		No such file exists.  *\li	#ISC_R_INVALIDFILE  *		The path specified was not usable by the operating system.  *\li	#ISC_R_NOPERM  *		The file's metainformation could not be retrieved because  *		permission was denied to some part of the file's path.  *\li	#ISC_R_IOERROR  *		Hardware error interacting with the filesystem.  *\li	#ISC_R_UNEXPECTED  *		Something totally unexpected happened.  *  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_mktemplate
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Generate a template string suitable for use with isc_file_openunique().  *  * Notes:  *\li	This function is intended to make creating temporary files  *	portable between different operating systems.  *  *\li	The path is prepended to an implementation-defined string and  *	placed into buf.  The string has no path characters in it,  *	and its maximum length is 14 characters plus a NUL.  Thus  *	buflen should be at least strlen(path) + 15 characters or  *	an error will be returned.  *  * Requires:  *\li	buf != NULL.  *  * Ensures:  *\li	If result == #ISC_R_SUCCESS:  *		buf contains a string suitable for use as the template argument  *		to isc_file_openunique().  *  *\li	If result != #ISC_R_SUCCESS:  *		buf is unchanged.  *  * Returns:  *\li	#ISC_R_SUCCESS 	Success.  *\li	#ISC_R_NOSPACE	buflen indicates buf is too small for the catenation  *				of the path with the internal template string.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_openunique
parameter_list|(
name|char
modifier|*
name|templet
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_file_openuniqueprivate
parameter_list|(
name|char
modifier|*
name|templet
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_file_openuniquemode
parameter_list|(
name|char
modifier|*
name|templet
parameter_list|,
name|int
name|mode
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_file_bopenunique
parameter_list|(
name|char
modifier|*
name|templet
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_file_bopenuniqueprivate
parameter_list|(
name|char
modifier|*
name|templet
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_file_bopenuniquemode
parameter_list|(
name|char
modifier|*
name|templet
parameter_list|,
name|int
name|mode
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Create and open a file with a unique name based on 'templet'.  *	isc_file_bopen*() open the file in binary mode in Windows.  *	isc_file_open*() open the file in text mode in Windows.  *  * Notes:  *\li	'template' is a reserved work in C++.  If you want to complain  *	about the spelling of 'templet', first look it up in the  *	Merriam-Webster English dictionary. (http://www.m-w.com/)  *  *\li	This function works by using the template to generate file names.  *	The template must be a writable string, as it is modified in place.  *	Trailing X characters in the file name (full file name on Unix,  *	basename on Win32 -- eg, tmp-XXXXXX vs XXXXXX.tmp, respectively)  *	are replaced with ASCII characters until a non-existent filename  *	is found.  If the template does not include pathname information,  *	the files in the working directory of the program are searched.  *  *\li	isc_file_mktemplate is a good, portable way to get a template.  *  * Requires:  *\li	'fp' is non-NULL and '*fp' is NULL.  *  *\li	'template' is non-NULL, and of a form suitable for use by  *	the system as described above.  *  * Ensures:  *\li	If result is #ISC_R_SUCCESS:  *		*fp points to an stream opening in stdio's "w+" mode.  *  *\li	If result is not #ISC_R_SUCCESS:  *		*fp is NULL.  *  *		No file is open.  Even if one was created (but unable  *		to be reopened as a stdio FILE pointer) then it has been  *		removed.  *  *\li	This function does *not* ensure that the template string has not been  *	modified, even if the operation was unsuccessful.  *  * Returns:  *\li	#ISC_R_SUCCESS  *		Success.  *\li	#ISC_R_EXISTS  *		No file with a unique name could be created based on the  *		template.  *\li	#ISC_R_INVALIDFILE  *		The path specified was not usable by the operating system.  *\li	#ISC_R_NOPERM  *		The file could not be created because permission was denied  *		to some part of the file's path.  *\li	#ISC_R_IOERROR  *		Hardware error interacting with the filesystem.  *\li	#ISC_R_UNEXPECTED  *		Something totally unexpected happened.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_remove
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Remove the file named by 'filename'.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_rename
parameter_list|(
specifier|const
name|char
modifier|*
name|oldname
parameter_list|,
specifier|const
name|char
modifier|*
name|newname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Rename the file 'oldname' to 'newname'.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_file_exists
parameter_list|(
specifier|const
name|char
modifier|*
name|pathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Return #ISC_TRUE if the calling process can tell that the given file exists.  * Will not return true if the calling process has insufficient privileges  * to search the entire path.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_file_isabsolute
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Return #ISC_TRUE if the given file name is absolute.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_isplainfile
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Check that the file is a plain file  *  * Returns:  *\li	#ISC_R_SUCCESS  *		Success. The file is a plain file.  *\li	#ISC_R_INVALIDFILE  *		The path specified was not usable by the operating system.  *\li	#ISC_R_FILENOTFOUND  *		The file does not exist. This return code comes from  *		errno=ENOENT when stat returns -1. This code is mentioned  *		here, because in logconf.c, it is the one rcode that is  *		permitted in addition to ISC_R_SUCCESS. This is done since  *		the next call in logconf.c is to isc_stdio_open(), which  *		will create the file if it can.  *\li	other ISC_R_* errors translated from errno  *		These occur when stat returns -1 and an errno.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_isdirectory
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Check that 'name' exists and is a directory.  *  * Returns:  *\li	#ISC_R_SUCCESS  *		Success, file is a directory.  *\li	#ISC_R_INVALIDFILE  *		File is not a directory.  *\li	#ISC_R_FILENOTFOUND  *		File does not exist.  *\li	other ISC_R_* errors translated from errno  *		These occur when stat returns -1 and an errno.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_file_iscurrentdir
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Return #ISC_TRUE if the given file name is the current directory (".").  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_file_ischdiridempotent
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return #ISC_TRUE if calling chdir(filename) multiple times will give  * the same result as calling it once.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|isc_file_basename
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the final component of the path in the file name.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_progname
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Given an operating system specific file name "filename"  * referring to a program, return the canonical program name.  *  *  * Any directory prefix or executable file name extension (if  * used on the OS in case) is stripped.  On systems where program  * names are case insensitive, the name is canonicalized to all  * lower case.  The name is written to 'buf', an array of 'buflen'  * chars, and null terminated.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOSPACE 	The name did not fit in 'buf'.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_template
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|templet
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create an OS specific template using 'path' to define the directory  * 'templet' to describe the filename and store the result in 'buf'  * such that path can be renamed to buf atomically.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_renameunique
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|templet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Rename 'file' using 'templet' as a template for the new file name.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_absolutepath
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|size_t
name|pathlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Given a file name, return the fully qualified path to the file.  */
end_comment

begin_comment
comment|/*  * XXX We should also have a isc_file_writeeopen() function  * for safely open a file in a publicly writable directory  * (see write_open() in BIND 8's ns_config.c).  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_truncate
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|isc_offset_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Truncate/extend the file specified to 'size' bytes.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_safecreate
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|FILE
modifier|*
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Open 'filename' for writing, truncating if necessary.  Ensure that  * if it existed it was a normal file.  If creating the file, ensure  * that only the owner can read/write it.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_splitpath
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
modifier|*
name|dirname
parameter_list|,
name|char
modifier|*
modifier|*
name|basename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Split a path into dirname and basename.  If 'path' contains no slash  * (or, on windows, backslash), then '*dirname' is set to ".".  *  * Allocates memory for '*dirname', which can be freed with isc_mem_free().  *  * Returns:  * - ISC_R_SUCCESS on success  * - ISC_R_INVALIDFILE if 'path' is empty or ends with '/'  * - ISC_R_NOMEMORY if unable to allocate memory  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_file_getsizefd
parameter_list|(
name|int
name|fd
parameter_list|,
name|off_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the size of the file (stored in the parameter pointed  * to by 'size') in bytes.  *  * Returns:  * - ISC_R_SUCCESS on success  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_FILE_H */
end_comment

end_unit

