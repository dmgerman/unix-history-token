begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: util.h,v $$Revision: 4.1 $$Date: 92/08/07 18:29:30 $  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log:	util.h,v $  */
end_comment

begin_comment
comment|/* is the string for makedir a directory name or a filename? */
end_comment

begin_define
define|#
directive|define
name|fatal
value|Myfatal
end_define

begin_define
define|#
directive|define
name|MD_DIR
value|0
end_define

begin_define
define|#
directive|define
name|MD_FILE
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SETUIDGID
end_ifdef

begin_function_decl
name|int
name|eaccess
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|makedir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpy2
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|int
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpytill
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|int
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|growstr
parameter_list|(
name|char
modifier|*
modifier|*
name|strptr
parameter_list|,
name|int
modifier|*
name|curlen
parameter_list|,
name|int
name|newlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|instr
parameter_list|(
name|char
modifier|*
name|big
parameter_list|,
name|char
modifier|*
name|little
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safecpy
parameter_list|(
name|char
modifier|*
name|to
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|croak
parameter_list|(
name|char
modifier|*
name|pat
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
name|char
modifier|*
name|pat
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warn
parameter_list|(
name|char
modifier|*
name|pat
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prewalk
parameter_list|(
name|int
name|numit
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|node
parameter_list|,
name|int
modifier|*
name|numericptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Malloc_t
name|safemalloc
parameter_list|(
name|MEM_SIZE
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Malloc_t
name|safecalloc
parameter_list|(
name|MEM_SIZE
name|elements
parameter_list|,
name|MEM_SIZE
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Malloc_t
name|saferealloc
parameter_list|(
name|Malloc_t
name|where
parameter_list|,
name|MEM_SIZE
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Free_t
name|safefree
parameter_list|(
name|Malloc_t
name|where
parameter_list|)
function_decl|;
end_function_decl

end_unit

