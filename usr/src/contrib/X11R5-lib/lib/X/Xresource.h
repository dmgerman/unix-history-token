begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xresource.h,v 1.35 91/04/13 10:50:30 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XRESOURCE_H_
end_ifndef

begin_define
define|#
directive|define
name|_XRESOURCE_H_
end_define

begin_comment
comment|/* You must include<X11/Xlib.h> before including this file */
end_comment

begin_comment
comment|/****************************************************************  ****************************************************************  ***                                                          ***  ***                                                          ***  ***          X Resource Manager Intrinsics                   ***  ***                                                          ***  ***                                                          ***  ****************************************************************  ****************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/****************************************************************  *  * Memory Management  *  ****************************************************************/
specifier|extern
name|char
modifier|*
name|Xpermalloc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|int
comment|/* size */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Quark Management  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
name|int
name|XrmQuark
typedef|,
modifier|*
name|XrmQuarkList
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLQUARK
value|((XrmQuark) 0)
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|XrmString
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLSTRING
value|((XrmString) 0)
end_define

begin_comment
comment|/* find quark for string, create new quark if none already exists */
end_comment

begin_function_decl
specifier|extern
name|XrmQuark
name|XrmStringToQuark
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmQuark
name|XrmPermStringToQuark
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find string for quark */
end_comment

begin_function_decl
specifier|extern
name|XrmString
name|XrmQuarkToString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmQuark
comment|/* quark */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmQuark
name|XrmUniqueQuark
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XrmStringsEqual
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|(strcmp(a1, a2) == 0)
end_define

begin_comment
comment|/****************************************************************  *  * Conversion of Strings to Lists  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XrmBindTightly
block|,
name|XrmBindLoosely
block|}
name|XrmBinding
operator|,
typedef|*
name|XrmBindingList
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|XrmStringToQuarkList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* string */
parameter_list|,
name|XrmQuarkList
comment|/* quarks_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmStringToBindingQuarkList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* string */
parameter_list|,
name|XrmBindingList
comment|/* bindings_return */
parameter_list|,
name|XrmQuarkList
comment|/* quarks_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Name and Class lists.  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
name|XrmQuark
name|XrmName
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XrmQuarkList
name|XrmNameList
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XrmNameToString
parameter_list|(
name|name
parameter_list|)
value|XrmQuarkToString(name)
end_define

begin_define
define|#
directive|define
name|XrmStringToName
parameter_list|(
name|string
parameter_list|)
value|XrmStringToQuark(string)
end_define

begin_define
define|#
directive|define
name|XrmStringToNameList
parameter_list|(
name|str
parameter_list|,
name|name
parameter_list|)
value|XrmStringToQuarkList(str, name)
end_define

begin_typedef
typedef|typedef
name|XrmQuark
name|XrmClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XrmQuarkList
name|XrmClassList
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XrmClassToString
parameter_list|(
name|class
parameter_list|)
value|XrmQuarkToString(class)
end_define

begin_define
define|#
directive|define
name|XrmStringToClass
parameter_list|(
name|class
parameter_list|)
value|XrmStringToQuark(class)
end_define

begin_define
define|#
directive|define
name|XrmStringToClassList
parameter_list|(
name|str
parameter_list|,
name|class
parameter_list|)
value|XrmStringToQuarkList(str, class)
end_define

begin_comment
comment|/****************************************************************  *  * Resource Representation Types and Values  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
name|XrmQuark
name|XrmRepresentation
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XrmStringToRepresentation
parameter_list|(
name|string
parameter_list|)
value|XrmStringToQuark(string)
end_define

begin_define
define|#
directive|define
name|XrmRepresentationToString
parameter_list|(
name|type
parameter_list|)
value|XrmQuarkToString(type)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|size
decl_stmt|;
name|XPointer
name|addr
decl_stmt|;
block|}
name|XrmValue
operator|,
typedef|*
name|XrmValuePtr
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Resource Manager Functions  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
name|struct
name|_XrmHashBucketRec
modifier|*
name|XrmHashBucket
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XrmHashBucket
modifier|*
name|XrmHashTable
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XrmHashTable
name|XrmSearchList
index|[]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XrmHashBucketRec
modifier|*
name|XrmDatabase
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|XrmDestroyDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* database */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmQPutResource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
modifier|*
comment|/* database */
parameter_list|,
name|XrmBindingList
comment|/* bindings */
parameter_list|,
name|XrmQuarkList
comment|/* quarks */
parameter_list|,
name|XrmRepresentation
comment|/* type */
parameter_list|,
name|XrmValue
modifier|*
comment|/* value */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmPutResource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
modifier|*
comment|/* database */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* specifier */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* type */
parameter_list|,
name|XrmValue
modifier|*
comment|/* value */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmQPutStringResource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
modifier|*
comment|/* database */
parameter_list|,
name|XrmBindingList
comment|/* bindings */
parameter_list|,
name|XrmQuarkList
comment|/* quarks */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* value */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmPutStringResource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
modifier|*
comment|/* database */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* specifier */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* value */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmPutLineResource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
modifier|*
comment|/* database */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* line */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern  XrmQGetResource(
if|#
directive|if
name|NeedFunctionPrototypes
extern|XrmDatabase
comment|/* database */
operator|,
extern|XrmNameList
comment|/* quark_name */
operator|,
extern|XrmClassList
comment|/* quark_class */
operator|,
extern|XrmRepresentation*
comment|/* quark_type_return */
operator|,
extern|XrmValue*
end_extern

begin_comment
comment|/* value_return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|Bool
name|XrmGetResource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* database */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* str_name */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* str_class */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* str_type_return */
parameter_list|,
name|XrmValue
modifier|*
comment|/* value_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XrmQGetSearchList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* database */
parameter_list|,
name|XrmNameList
comment|/* names */
parameter_list|,
name|XrmClassList
comment|/* classes */
parameter_list|,
name|XrmSearchList
comment|/* list_return */
parameter_list|,
name|int
comment|/* list_length */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XrmQGetSearchResource
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmSearchList
comment|/* list */
parameter_list|,
name|XrmName
comment|/* name */
parameter_list|,
name|XrmClass
comment|/* class */
parameter_list|,
name|XrmRepresentation
modifier|*
comment|/* type_return */
parameter_list|,
name|XrmValue
modifier|*
comment|/* value_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Resource Database Management  *  ****************************************************************/
end_comment

begin_function_decl
specifier|extern
name|void
name|XrmSetDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XrmDatabase
comment|/* database */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmDatabase
name|XrmGetDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmDatabase
name|XrmGetFileDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* filename */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XrmCombineFileDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* filename */
parameter_list|,
name|XrmDatabase
modifier|*
comment|/* target */
parameter_list|,
name|Bool
comment|/* override */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmDatabase
name|XrmGetStringDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* data */
comment|/*  null terminated string */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmPutFileDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* database */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* filename */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmMergeDatabases
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* source_db */
parameter_list|,
name|XrmDatabase
modifier|*
comment|/* target_db */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmCombineDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* source_db */
parameter_list|,
name|XrmDatabase
modifier|*
comment|/* target_db */
parameter_list|,
name|Bool
comment|/* override */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XrmEnumAllLevels
value|0
end_define

begin_define
define|#
directive|define
name|XrmEnumOneLevel
value|1
end_define

begin_function_decl
specifier|extern
name|Bool
name|XrmEnumerateDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* db */
parameter_list|,
name|XrmNameList
comment|/* name_prefix */
parameter_list|,
name|XrmClassList
comment|/* class_prefix */
parameter_list|,
name|int
comment|/* mode */
parameter_list|,
name|Bool
function_decl|(
modifier|*
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedNestedPrototypes
name|XrmDatabase
modifier|*
comment|/* db */
parameter_list|,
name|XrmBindingList
comment|/* bindings */
parameter_list|,
name|XrmQuarkList
comment|/* quarks */
parameter_list|,
name|XrmRepresentation
modifier|*
comment|/* type */
parameter_list|,
name|XrmValue
modifier|*
comment|/* value */
parameter_list|,
name|XPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
comment|/* proc */
parameter_list|,
name|XPointer
comment|/* closure */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XrmLocaleOfDatabase
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
comment|/* database */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************  *  * Command line option mapping to resource entries  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XrmoptionNoArg
block|,
comment|/* Value is specified in OptionDescRec.value	    */
name|XrmoptionIsArg
block|,
comment|/* Value is the option string itself		    */
name|XrmoptionStickyArg
block|,
comment|/* Value is characters immediately following option */
name|XrmoptionSepArg
block|,
comment|/* Value is next argument in argv		    */
name|XrmoptionResArg
block|,
comment|/* Resource and value in next argument in argv      */
name|XrmoptionSkipArg
block|,
comment|/* Ignore this option and the next argument in argv */
name|XrmoptionSkipLine
block|,
comment|/* Ignore this option and the rest of argv	    */
name|XrmoptionSkipNArgs
comment|/* Ignore this option and the next  			   OptionDescRes.value arguments in argv */
block|}
name|XrmOptionKind
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|option
decl_stmt|;
comment|/* Option abbreviation in argv	    */
name|char
modifier|*
name|specifier
decl_stmt|;
comment|/* Resource specifier		    */
name|XrmOptionKind
name|argKind
decl_stmt|;
comment|/* Which style of option it is	    */
name|XPointer
name|value
decl_stmt|;
comment|/* Value to provide if XrmoptionNoArg   */
block|}
name|XrmOptionDescRec
operator|,
typedef|*
name|XrmOptionDescList
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|XrmParseCommand
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XrmDatabase
modifier|*
comment|/* database */
parameter_list|,
name|XrmOptionDescList
comment|/* table */
parameter_list|,
name|int
comment|/* table_count */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
parameter_list|,
name|int
modifier|*
comment|/* argc_in_out */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* argv_in_out */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XRESOURCE_H_ */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

