begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: linker.h,v 1.1 1997/05/07 16:05:45 dfr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LINKER_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LINKER_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|M_LINKER
value|M_TEMP
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Object representing a file which has been loaded by the linker.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|linker_file
modifier|*
name|linker_file_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|linker_file
argument_list|)
name|linker_file_list_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|linker_file_ops
block|{
comment|/*      * Lookup a symbol in the file's symbol table.  If the symbol is      * not found then return ENOENT, otherwise zero.  If the symbol      * found is a common symbol, return with *address set to zero and      * *size set to the size of the common space required.  Otherwise      * set *address the value of the symbol.      */
name|int
function_decl|(
modifier|*
name|lookup_symbol
function_decl|)
parameter_list|(
name|linker_file_t
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|caddr_t
modifier|*
name|address
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
comment|/*      * Unload a file, releasing dependancies and freeing storage.      */
name|void
function_decl|(
modifier|*
name|unload
function_decl|)
parameter_list|(
name|linker_file_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|common_symbol
block|{
name|STAILQ_ENTRY
argument_list|(
argument|common_symbol
argument_list|)
name|link
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|caddr_t
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linker_file
block|{
name|int
name|refs
decl_stmt|;
comment|/* reference count */
name|int
name|userrefs
decl_stmt|;
comment|/* modload(2) count */
name|TAILQ_ENTRY
argument_list|(
argument|linker_file
argument_list|)
name|link
expr_stmt|;
comment|/* list of all loaded files */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* file which was loaded */
name|int
name|id
decl_stmt|;
comment|/* unique id */
name|caddr_t
name|address
decl_stmt|;
comment|/* load address */
name|size_t
name|size
decl_stmt|;
comment|/* size of file */
name|int
name|ndeps
decl_stmt|;
comment|/* number of dependancies */
name|linker_file_t
modifier|*
name|deps
decl_stmt|;
comment|/* list of dependancies */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|common_symbol
argument_list|)
name|common
expr_stmt|;
comment|/* list of common symbols */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|module
argument_list|)
name|modules
expr_stmt|;
comment|/* modules in this file */
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* implementation data */
name|struct
name|linker_file_ops
modifier|*
name|ops
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Object implementing a class of file (a.out, elf, etc.)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|linker_class
modifier|*
name|linker_class_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|linker_class
argument_list|)
name|linker_class_list_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|linker_class_ops
block|{
comment|/*       * Load a file, returning the new linker_file_t in *result.  If      * the class does not recognise the file type, zero should be      * returned, without modifying *result.  If the file is      * recognised, the file should be loaded, *result set to the new      * file and zero returned.  If some other error is detected an      * appropriate errno should be returned.      */
name|int
function_decl|(
modifier|*
name|load_file
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|linker_file_t
modifier|*
name|result
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linker_class
block|{
name|TAILQ_ENTRY
argument_list|(
argument|linker_class
argument_list|)
name|link
expr_stmt|;
comment|/* list of all file classes */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* description (e.g. "a.out") */
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* implementation data */
name|struct
name|linker_class_ops
modifier|*
name|ops
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The file which is currently loading.  Used to register modules with  * the files which contain them.  */
end_comment

begin_decl_stmt
specifier|extern
name|linker_file_t
name|linker_current_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Add a new file class to the linker.  */
end_comment

begin_function_decl
name|int
name|linker_add_class
parameter_list|(
specifier|const
name|char
modifier|*
name|desc
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|linker_class_ops
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Load a file, trying each file class until one succeeds.  */
end_comment

begin_function_decl
name|int
name|linker_load_file
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|linker_file_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find a currently loaded file given its filename.  */
end_comment

begin_function_decl
name|linker_file_t
name|linker_find_file_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find a currently loaded file given its file id.  */
end_comment

begin_function_decl
name|linker_file_t
name|linker_find_file_by_id
parameter_list|(
name|int
name|fileid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Called from a class handler when a file is laoded.  */
end_comment

begin_function_decl
name|linker_file_t
name|linker_make_file
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|struct
name|linker_file_ops
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unload a file, freeing up memory.  */
end_comment

begin_function_decl
name|int
name|linker_file_unload
parameter_list|(
name|linker_file_t
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a dependancy to a file.  */
end_comment

begin_function_decl
name|int
name|linker_file_add_dependancy
parameter_list|(
name|linker_file_t
name|file
parameter_list|,
name|linker_file_t
name|dep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lookup a symbol in a file.  If deps is TRUE, look in dependancies  * if not found in file.  */
end_comment

begin_function_decl
name|caddr_t
name|linker_file_lookup_symbol
parameter_list|(
name|linker_file_t
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|deps
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KLD_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|kld_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KLD_DEBUG_FILE
value|1
end_define

begin_comment
comment|/* file load/unload */
end_comment

begin_define
define|#
directive|define
name|KLD_DEBUG_SYM
value|2
end_define

begin_comment
comment|/* symbol lookup */
end_comment

begin_define
define|#
directive|define
name|KLD_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
define|\
value|do {							\ 		if (KLD_debug& KLD_DEBUG_##cat) printf args;	\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KLD_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_struct
struct|struct
name|kld_file_stat
block|{
name|int
name|version
decl_stmt|;
comment|/* set to sizeof(linker_file_stat) */
name|char
name|name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|int
name|refs
decl_stmt|;
name|int
name|id
decl_stmt|;
name|caddr_t
name|address
decl_stmt|;
comment|/* load address */
name|size_t
name|size
decl_stmt|;
comment|/* size in bytes */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|kldload
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldunload
parameter_list|(
name|int
name|fileid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldfind
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldnext
parameter_list|(
name|int
name|fileid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldstat
parameter_list|(
name|int
name|fileid
parameter_list|,
name|struct
name|kld_file_stat
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kldfirstmod
parameter_list|(
name|int
name|fileid
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KLD_H_ */
end_comment

end_unit

