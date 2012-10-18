begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: apropos_db.h,v 1.13 2012/03/24 01:46:25 kristaps Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011, 2012 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APROPOS_H
end_ifndef

begin_define
define|#
directive|define
name|APROPOS_H
end_define

begin_enum
enum|enum
name|restype
block|{
name|RESTYPE_MAN
block|,
comment|/* man(7) file */
name|RESTYPE_MDOC
block|,
comment|/* mdoc(7) file */
name|RESTYPE_CAT
comment|/* pre-formatted file */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|res
block|{
name|enum
name|restype
name|type
decl_stmt|;
comment|/* input file type */
name|char
modifier|*
name|file
decl_stmt|;
comment|/* file in file-system */
name|char
modifier|*
name|cat
decl_stmt|;
comment|/* category (3p, 3, etc.) */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* title (FOO, etc.) */
name|char
modifier|*
name|arch
decl_stmt|;
comment|/* arch (or empty string) */
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* description (from Nd) */
name|unsigned
name|int
name|rec
decl_stmt|;
comment|/* record in index */
comment|/* 	 * The index volume.  This indexes into the array of directories 	 * searched for manual page databases. 	 */
name|unsigned
name|int
name|volume
decl_stmt|;
comment|/* 	 * The following fields are used internally. 	 * 	 * Maintain a binary tree for checking the uniqueness of `rec' 	 * when adding elements to the results array. 	 * Since the results array is dynamic, use offset in the array 	 * instead of a pointer to the structure. 	 */
name|int
name|lhs
decl_stmt|;
name|int
name|rhs
decl_stmt|;
name|int
name|matched
decl_stmt|;
comment|/* expression is true */
name|int
modifier|*
name|matches
decl_stmt|;
comment|/* partial truth evaluations */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|opts
block|{
specifier|const
name|char
modifier|*
name|arch
decl_stmt|;
comment|/* restrict to architecture */
specifier|const
name|char
modifier|*
name|cat
decl_stmt|;
comment|/* restrict to manual section */
block|}
struct|;
end_struct

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|expr
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|apropos_search
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|opts
modifier|*
parameter_list|,
specifier|const
name|struct
name|expr
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|struct
name|res
modifier|*
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|res
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|expr
modifier|*
name|exprcomp
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exprfree
parameter_list|(
name|struct
name|expr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resfree
parameter_list|(
name|struct
name|res
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|expr
modifier|*
name|termcomp
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|,
name|size_t
modifier|*
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

begin_comment
comment|/*!APROPOS_H*/
end_comment

end_unit

