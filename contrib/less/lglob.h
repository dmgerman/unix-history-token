begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2000  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information about less, or for information on how to   * contact the author, see the README file.  */
end_comment

begin_comment
comment|/*  * Macros to define the method of doing filename "globbing".  * There are three possible mechanisms:  *   1.	GLOB_LIST  *	This defines a function that returns a list of matching filenames.  *   2. GLOB_NAME  *	This defines a function that steps thru the list of matching  *	filenames, returning one name each time it is called.  *   3. GLOB_STRING  *	This defines a function that returns the complete list of  *	matching filenames as a single space-separated string.  */
end_comment

begin_if
if|#
directive|if
name|OS2
end_if

begin_define
define|#
directive|define
name|DECL_GLOB_LIST
parameter_list|(
name|list
parameter_list|)
value|char **list;  char **pp;
end_define

begin_define
define|#
directive|define
name|GLOB_LIST
parameter_list|(
name|filename
parameter_list|,
name|list
parameter_list|)
value|list = _fnexplode(filename)
end_define

begin_define
define|#
directive|define
name|GLOB_LIST_FAILED
parameter_list|(
name|list
parameter_list|)
value|list == NULL
end_define

begin_define
define|#
directive|define
name|SCAN_GLOB_LIST
parameter_list|(
name|list
parameter_list|,
name|p
parameter_list|)
value|pp = list;  *pp != NULL;  pp++
end_define

begin_define
define|#
directive|define
name|INIT_GLOB_LIST
parameter_list|(
name|list
parameter_list|,
name|p
parameter_list|)
value|p = *pp
end_define

begin_define
define|#
directive|define
name|GLOB_LIST_DONE
parameter_list|(
name|list
parameter_list|)
value|_fnexplodefree(list)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|==
name|DJGPPC
end_if

begin_define
define|#
directive|define
name|DECL_GLOB_LIST
parameter_list|(
name|list
parameter_list|)
value|glob_t list;  int i;
end_define

begin_define
define|#
directive|define
name|GLOB_LIST
parameter_list|(
name|filename
parameter_list|,
name|list
parameter_list|)
value|glob(filename,GLOB_NOCHECK,0,&list)
end_define

begin_define
define|#
directive|define
name|GLOB_LIST_FAILED
parameter_list|(
name|list
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|SCAN_GLOB_LIST
parameter_list|(
name|list
parameter_list|,
name|p
parameter_list|)
value|i = 0;  i< list.gl_pathc;  i++
end_define

begin_define
define|#
directive|define
name|INIT_GLOB_LIST
parameter_list|(
name|list
parameter_list|,
name|p
parameter_list|)
value|p = list.gl_pathv[i]
end_define

begin_define
define|#
directive|define
name|GLOB_LIST_DONE
parameter_list|(
name|list
parameter_list|)
value|globfree(&list)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|==
name|MSOFTC
operator|||
name|MSDOS_COMPILER
operator|==
name|BORLANDC
end_if

begin_define
define|#
directive|define
name|GLOB_FIRST_NAME
parameter_list|(
name|filename
parameter_list|,
name|fndp
parameter_list|,
name|h
parameter_list|)
value|h = _dos_findfirst(filename, ~_A_VOLID, fndp)
end_define

begin_define
define|#
directive|define
name|GLOB_FIRST_FAILED
parameter_list|(
name|handle
parameter_list|)
value|((handle) != 0)
end_define

begin_define
define|#
directive|define
name|GLOB_NEXT_NAME
parameter_list|(
name|handle
parameter_list|,
name|fndp
parameter_list|)
value|_dos_findnext(fndp)
end_define

begin_define
define|#
directive|define
name|GLOB_NAME_DONE
parameter_list|(
name|handle
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GLOB_NAME
value|name
end_define

begin_define
define|#
directive|define
name|DECL_GLOB_NAME
parameter_list|(
name|fnd
parameter_list|,
name|drive
parameter_list|,
name|dir
parameter_list|,
name|fname
parameter_list|,
name|ext
parameter_list|,
name|handle
parameter_list|)
define|\
value|struct find_t fnd;	\ 					char drive[_MAX_DRIVE];	\ 					char dir[_MAX_DIR];	\ 					char fname[_MAX_FNAME];	\ 					char ext[_MAX_EXT];	\ 					int handle;
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|==
name|WIN32C
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|GLOB_FIRST_NAME
parameter_list|(
name|filename
parameter_list|,
name|fndp
parameter_list|,
name|h
parameter_list|)
value|h = _findfirst(filename, fndp)
end_define

begin_define
define|#
directive|define
name|GLOB_FIRST_FAILED
parameter_list|(
name|handle
parameter_list|)
value|((handle) == -1)
end_define

begin_define
define|#
directive|define
name|GLOB_NEXT_NAME
parameter_list|(
name|handle
parameter_list|,
name|fndp
parameter_list|)
value|_findnext(handle, fndp)
end_define

begin_define
define|#
directive|define
name|GLOB_NAME_DONE
parameter_list|(
name|handle
parameter_list|)
value|_findclose(handle)
end_define

begin_define
define|#
directive|define
name|GLOB_NAME
value|name
end_define

begin_define
define|#
directive|define
name|DECL_GLOB_NAME
parameter_list|(
name|fnd
parameter_list|,
name|drive
parameter_list|,
name|dir
parameter_list|,
name|fname
parameter_list|,
name|ext
parameter_list|,
name|handle
parameter_list|)
define|\
value|struct _finddata_t fnd;	\ 					char drive[_MAX_DRIVE];	\ 					char dir[_MAX_DIR];	\ 					char fname[_MAX_FNAME];	\ 					char ext[_MAX_EXT];	\ 					long handle;
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MSDOS_COMPILER
operator|==
name|WIN32C
operator|&&
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|/* Borland C for Windows */
end_comment

begin_define
define|#
directive|define
name|GLOB_FIRST_NAME
parameter_list|(
name|filename
parameter_list|,
name|fndp
parameter_list|,
name|h
parameter_list|)
value|h = findfirst(filename, fndp, ~FA_LABEL)
end_define

begin_define
define|#
directive|define
name|GLOB_FIRST_FAILED
parameter_list|(
name|handle
parameter_list|)
value|((handle) != 0)
end_define

begin_define
define|#
directive|define
name|GLOB_NEXT_NAME
parameter_list|(
name|handle
parameter_list|,
name|fndp
parameter_list|)
value|findnext(fndp)
end_define

begin_define
define|#
directive|define
name|GLOB_NAME_DONE
parameter_list|(
name|handle
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GLOB_NAME
value|ff_name
end_define

begin_define
define|#
directive|define
name|DECL_GLOB_NAME
parameter_list|(
name|fnd
parameter_list|,
name|drive
parameter_list|,
name|dir
parameter_list|,
name|fname
parameter_list|,
name|ext
parameter_list|,
name|handle
parameter_list|)
define|\
value|struct ffblk fnd;	\ 					char drive[MAXDRIVE];	\ 					char dir[MAXDIR];	\ 					char fname[MAXFILE];	\ 					char ext[MAXEXT];	\ 					int handle;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

