begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: file.h,v 1.24.12.3 2004/03/08 09:04:51 marka Exp $ */
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
comment|/*  * Get the time of last modication of a file.  *  * Notes:  *	The time that is set is relative to the (OS-specific) epoch, as are  *	all isc_time_t structures.  *  * Requires:  *	file != NULL.  *	time != NULL.  *  * Ensures:  *	If the file could not be accessed, 'time' is unchanged.  *  * Returns:  *	ISC_R_SUCCESS  *		Success.  *	ISC_R_NOTFOUND  *		No such file exists.  *	ISC_R_INVALIDFILE  *		The path specified was not usable by the operating system.  *	ISC_R_NOPERM  *		The file's metainformation could not be retrieved because  *		permission was denied to some part of the file's path.  *	ISC_R_EIO  *		Hardware error interacting with the filesystem.  *	ISC_R_UNEXPECTED  *		Something totally unexpected happened.  *  */
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
comment|/*  * Generate a template string suitable for use with isc_file_openunique.  *  * Notes:  *	This function is intended to make creating temporary files  *	portable between different operating systems.  *  *	The path is prepended to an implementation-defined string and  *	placed into buf.  The string has no path characters in it,  *	and its maximum length is 14 characters plus a NUL.  Thus  *	buflen should be at least strlen(path) + 15 characters or  *	an error will be returned.  *  * Requires:  *	buf != NULL.  *  * Ensures:  *	If result == ISC_R_SUCCESS:  *		buf contains a string suitable for use as the template argument  *		to isc_file_openunique.  *  *	If result != ISC_R_SUCCESS:  *		buf is unchanged.  *  * Returns:  *	ISC_R_SUCCESS 	Success.  *	ISC_R_NOSPACE	buflen indicates buf is too small for the catenation  *				of the path with the internal template string.  */
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

begin_comment
comment|/*  * Create and open a file with a unique name based on 'templet'.  *  * Notes:  *	'template' is a reserved work in C++.  If you want to complain  *	about the spelling of 'templet', first look it up in the  *	Merriam-Webster English dictionary. (http://www.m-w.com/)  *  *	This function works by using the template to generate file names.  *	The template must be a writable string, as it is modified in place.  *	Trailing X characters in the file name (full file name on Unix,  *	basename on Win32 -- eg, tmp-XXXXXX vs XXXXXX.tmp, respectively)  *	are replaced with ASCII characters until a non-existent filename  *	is found.  If the template does not include pathname information,  *	the files in the working directory of the program are searched.  *  *	isc_file_mktemplate is a good, portable way to get a template.  *  * Requires:  *	'fp' is non-NULL and '*fp' is NULL.  *  *	'template' is non-NULL, and of a form suitable for use by  *	the system as described above.  *  * Ensures:  *	If result is ISC_R_SUCCESS:  *		*fp points to an stream opening in stdio's "w+" mode.  *  *	If result is not ISC_R_SUCCESS:  *		*fp is NULL.  *  *		No file is open.  Even if one was created (but unable  *		to be reopened as a stdio FILE pointer) then it has been  *		removed.  *  *	This function does *not* ensure that the template string has not been  *	modified, even if the operation was unsuccessful.  *  * Returns:  *	ISC_R_SUCCESS  *		Success.  *	ISC_R_EXISTS  *		No file with a unique name could be created based on the  *		template.  *	ISC_R_INVALIDFILE  *		The path specified was not usable by the operating system.  *	ISC_R_NOPERM  *		The file could not be created because permission was denied  *		to some part of the file's path.  *	ISC_R_EIO  *		Hardware error interacting with the filesystem.  *	ISC_R_UNEXPECTED  *		Something totally unexpected happened.  */
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
comment|/*  * Remove the file named by 'filename'.  */
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
comment|/*  * Rename the file 'oldname' to 'newname'.  */
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
comment|/*  * Return ISC_TRUE iff the calling process can tell that the given file exists.  * Will not return true if the calling process has insufficient privileges  * to search the entire path.  */
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
comment|/*  * Return ISC_TRUE iff the given file name is absolute.  */
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
comment|/*  * Return ISC_TRUE iff the given file name is the current directory (".").  */
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
comment|/*  * Return ISC_TRUE if calling chdir(filename) multiple times will give  * the same result as calling it once.  */
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
comment|/*  * Return the final component of the path in the file name.  */
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
comment|/*  * Given an operating system specific file name "filename"  * referring to a program, return the canonical program name.   * Any directory prefix or executable file name extension (if  * used on the OS in case) is stripped.  On systems where program  * names are case insensitive, the name is canonicalized to all  * lower case.  The name is written to 'buf', an array of 'buflen'  * chars, and null terminated.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOSPACE 	The name did not fit in 'buf'.  */
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
comment|/*  * Create an OS specific template using 'path' to define the directory  * 'templet' to describe the filename and store the result in 'buf'  * such that path can be renamed to buf atomically.  */
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
comment|/*  * Rename 'file' using 'templet' as a template for the new file name.  */
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
comment|/*  * Given a file name, return the fully qualified path to the file.  */
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
comment|/*  * Truncate/extend the file specified to 'size' bytes.  */
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

