begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	Header file for XNS Courier compiler	*/
end_comment

begin_comment
comment|/* $Header: compiler.h,v 2.2 86/06/06 07:28:35 jqj Exp $ */
end_comment

begin_comment
comment|/* $Log:	compiler.h,v $  * Revision 2.2  86/06/06  07:28:35  jqj  * many mods for better symbol table management:  added CurrentModule,  *  made check_dependency, make_symbol, check_def set/use/use a symbol  *  table instead of a module name string, etc.  Result is that we can  *  now handle DEPENDS UPON 2 versions of same program.  *   * Revision 2.1  86/05/16  05:44:42  jqj  * make enumeration tags local to modules rather than global, to allow  * DEPENDS UPON two versions of the same program.  For same reason, use  * gensymed symbol names that include version number.  *   * Revision 2.0  85/11/21  07:21:30  jqj  * 4.3BSD standard release  *   * Revision 1.5  85/05/23  06:19:24  jqj  * *** empty log message ***  *   * Revision 1.5  85/05/23  06:19:24  jqj  * Public Beta-test version, released 24 May 1985  *   * Revision 1.4  85/03/26  06:09:31  jqj  * Revised public alpha-test version, released 26 March 1985  *   * Revision 1.3  85/03/11  16:38:47  jqj  * Public alpha-test version, released 11 March 1985  *   * Revision 1.2  85/02/21  11:04:54  jqj  * alpha test version  *   * Revision 1.1  85/02/15  13:58:15  jqj  * Initial revision  *   */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|MAXSTR
value|200
end_define

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(strcmp(s, t) == 0)
end_define

begin_define
define|#
directive|define
name|New
parameter_list|(
name|t
parameter_list|)
value|((t *) calloc(1, sizeof(t)))
end_define

begin_comment
comment|/*  * error message severity types  */
end_comment

begin_enum
enum|enum
name|severity
block|{
name|WARNING
block|,
name|ERROR
block|,
name|FATAL
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Cons cell for lisp operations.  */
end_comment

begin_struct
struct|struct
name|cons
block|{
name|struct
name|cons
modifier|*
name|c_cdr
decl_stmt|;
name|struct
name|cons
modifier|*
name|c_car
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cons
modifier|*
name|list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NIL
value|((list) 0)
end_define

begin_define
define|#
directive|define
name|car
parameter_list|(
name|x
parameter_list|)
value|((x)->c_car)
end_define

begin_define
define|#
directive|define
name|cdr
parameter_list|(
name|x
parameter_list|)
value|((x)->c_cdr)
end_define

begin_define
define|#
directive|define
name|caar
parameter_list|(
name|x
parameter_list|)
value|((x)->c_car->c_car)
end_define

begin_define
define|#
directive|define
name|cdar
parameter_list|(
name|x
parameter_list|)
value|((x)->c_car->c_cdr)
end_define

begin_define
define|#
directive|define
name|cadr
parameter_list|(
name|x
parameter_list|)
value|((x)->c_cdr->c_car)
end_define

begin_define
define|#
directive|define
name|cddr
parameter_list|(
name|x
parameter_list|)
value|((x)->c_cdr->c_cdr)
end_define

begin_define
define|#
directive|define
name|ONIL
value|((struct object *) 0)
end_define

begin_define
define|#
directive|define
name|ocar
parameter_list|(
name|x
parameter_list|)
value|((x)->o_car)
end_define

begin_define
define|#
directive|define
name|ocdr
parameter_list|(
name|x
parameter_list|)
value|((x)->o_cdr)
end_define

begin_define
define|#
directive|define
name|TNIL
value|((struct type *) 0)
end_define

begin_comment
comment|/*  * Object classes.  */
end_comment

begin_enum
enum|enum
name|class
block|{
name|O_UNKNOWN
init|=
literal|0
block|,
comment|/* make_symbol starts with this */
name|O_TYPE
block|,
comment|/* a typename symbol */
name|O_CONSTANT
block|,
comment|/* a constantname symbol */
name|O_ENUMTAG
block|,
comment|/* an enumeration tag */
name|O_SYMBOLTABLE
comment|/* a symbol table */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Type constructors.  */
end_comment

begin_enum
enum|enum
name|constr
block|{
name|C_NUMERIC
init|=
literal|1
block|,
name|C_BOOLEAN
block|,
name|C_STRING
block|,
name|C_ENUMERATION
block|,
name|C_ARRAY
block|,
name|C_SEQUENCE
block|,
name|C_RECORD
block|,
name|C_CHOICE
block|,
name|C_PROCEDURE
block|,
name|C_ERROR
block|}
enum|;
end_enum

begin_comment
comment|/*  * Object structure, for types, and constants.  * These are the symbol table entries!  */
end_comment

begin_struct
struct|struct
name|object
block|{
name|struct
name|object
modifier|*
name|o_cdr
decl_stmt|,
modifier|*
name|o_car
decl_stmt|;
comment|/* for a binary tree symbol table */
name|enum
name|class
name|o_class
decl_stmt|;
name|char
modifier|*
name|o_name
decl_stmt|;
comment|/* Courier name of this symbol */
name|char
modifier|*
name|o_module
decl_stmt|;
comment|/* name of module it appears in */
name|int
name|o_modnumber
decl_stmt|;
comment|/* number of module it appears in */
name|int
name|o_modversion
decl_stmt|;
comment|/* version of module it appears in */
union|union
block|{
name|struct
name|type
modifier|*
name|u_type
decl_stmt|;
name|struct
name|constant
modifier|*
name|u_constant
decl_stmt|;
name|struct
name|enumtag
modifier|*
name|u_enum
decl_stmt|;
name|struct
name|symtab
modifier|*
name|u_symboltable
decl_stmt|;
block|}
name|o_union
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|o_type
value|o_union.u_type
end_define

begin_define
define|#
directive|define
name|o_constant
value|o_union.u_constant
end_define

begin_define
define|#
directive|define
name|o_enum
value|o_union.u_enum
end_define

begin_define
define|#
directive|define
name|o_symboltable
value|o_union.u_symboltable
end_define

begin_define
define|#
directive|define
name|class_of
parameter_list|(
name|x
parameter_list|)
value|(((struct object *) x)->o_class)
end_define

begin_define
define|#
directive|define
name|name_of
parameter_list|(
name|x
parameter_list|)
value|(((struct object *) x)->o_name)
end_define

begin_define
define|#
directive|define
name|value_of
parameter_list|(
name|x
parameter_list|)
value|(((struct object *) x)->o_value->cn_value)
end_define

begin_define
define|#
directive|define
name|enumvalue_of
parameter_list|(
name|x
parameter_list|)
value|(((struct object *) x)->o_enum->en_value)
end_define

begin_define
define|#
directive|define
name|enumname_of
parameter_list|(
name|x
parameter_list|)
value|(((struct object *) x)->o_enum->en_name)
end_define

begin_comment
comment|/*  * Type structure.  *  * Formats of various lists are as follows.  * a-b is an a of type b.  * . indicates a cons operation.  * ... indicates a list of elements of the preceding form.  *  * enumeration:  *	((name-objectptr . value-numericstring) ...)  *	[ the value is irrelevant, since it is stored in the enumtag]  * record, error, procedure arguments, procedure results:  *	(((name-string) . type-typeptr) ...)  * choice:  *	((((name-symbol . value-numericstring) ...) . type-typeptr) ...)  *		[value may be nil if it is inherited from someplace]  */
end_comment

begin_struct
struct|struct
name|type
block|{
name|enum
name|constr
name|type_constr
decl_stmt|;
comment|/* constructor */
name|char
modifier|*
name|type_pfname
decl_stmt|;
comment|/* name of pack function */
name|char
modifier|*
name|type_ufname
decl_stmt|;
comment|/* name of unpack function */
name|char
modifier|*
name|type_name
decl_stmt|;
comment|/* name of C type */
name|int
name|type_xsize
decl_stmt|;
comment|/* size of external form in 16-bit 					   words, or -1 if variable */
union|union
block|{
name|list
name|u_list
decl_stmt|;
comment|/* enumeration, record, error */
struct|struct
block|{
name|int
name|u_size
decl_stmt|;
name|struct
name|type
modifier|*
name|u_basetype
decl_stmt|;
block|}
name|u_array
struct|;
comment|/* array, sequence */
struct|struct
block|{
name|struct
name|type
modifier|*
name|u_designator
decl_stmt|;
name|list
name|u_candidates
decl_stmt|;
block|}
name|u_choice
struct|;
comment|/* choice */
struct|struct
block|{
name|list
name|u_args
decl_stmt|,
name|u_results
decl_stmt|,
name|u_errors
decl_stmt|;
block|}
name|u_procedure
struct|;
comment|/* procedure */
block|}
name|type_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|typename
parameter_list|(
name|tp
parameter_list|)
value|(tp->type_name)
end_define

begin_define
define|#
directive|define
name|type_list
value|type_u.u_list
end_define

begin_define
define|#
directive|define
name|type_array
value|type_u.u_array
end_define

begin_define
define|#
directive|define
name|type_size
value|type_array.u_size
end_define

begin_define
define|#
directive|define
name|type_basetype
value|type_array.u_basetype
end_define

begin_define
define|#
directive|define
name|type_choice
value|type_u.u_choice
end_define

begin_define
define|#
directive|define
name|type_designator
value|type_choice.u_designator
end_define

begin_define
define|#
directive|define
name|type_candidates
value|type_choice.u_candidates
end_define

begin_define
define|#
directive|define
name|type_procedure
value|type_u.u_procedure
end_define

begin_define
define|#
directive|define
name|type_args
value|type_procedure.u_args
end_define

begin_define
define|#
directive|define
name|type_results
value|type_procedure.u_results
end_define

begin_define
define|#
directive|define
name|type_errors
value|type_procedure.u_errors
end_define

begin_comment
comment|/*  * These definitions allow access from an object pointer  * known to be a type.  */
end_comment

begin_define
define|#
directive|define
name|t_constr
value|o_type->type_constr
end_define

begin_define
define|#
directive|define
name|t_pfname
value|o_type->type_pfname
end_define

begin_define
define|#
directive|define
name|t_ufname
value|o_type->type_ufname
end_define

begin_define
define|#
directive|define
name|t_name
value|o_type->type_name
end_define

begin_define
define|#
directive|define
name|t_xsize
value|o_type->type_xsize
end_define

begin_define
define|#
directive|define
name|t_list
value|o_type->type_u.u_list
end_define

begin_define
define|#
directive|define
name|t_size
value|o_type->type_u.u_array.u_size
end_define

begin_define
define|#
directive|define
name|t_basetype
value|o_type->type_u.u_array.u_basetype
end_define

begin_define
define|#
directive|define
name|t_designator
value|o_type->type_u.u_choice.u_designator
end_define

begin_define
define|#
directive|define
name|t_candidates
value|o_type->type_u.u_choice.u_candidates
end_define

begin_define
define|#
directive|define
name|t_args
value|o_type->type_u.u_procedure.u_args
end_define

begin_define
define|#
directive|define
name|t_results
value|o_type->type_u.u_procedure.u_results
end_define

begin_define
define|#
directive|define
name|t_errors
value|o_type->type_u.u_procedure.u_errors
end_define

begin_comment
comment|/*  * constant definition structure.  *  *   Formats for cn_value follow:  * numeric constants, error constants  *	e.g.:  34  * string constants  *	e.g.:  "abc\"def"  * enumeration constants  *	e.g.:  red  *  *   Formats for cn_list follow:  * record  *	((name-string . constant) ...)  * choice:  *	(name-symbol . constant)  * array, sequence  *	(constant ...)  * error  *	(errorvalue-string . argsrecord-typtr)  * note that procedure and error constants are special.  */
end_comment

begin_struct
struct|struct
name|constant
block|{
name|enum
name|constr
name|cn_constr
decl_stmt|;
name|char
modifier|*
name|cn_name
decl_stmt|;
comment|/* name of the C constant */
name|char
modifier|*
name|cn_seqvalname
decl_stmt|;
comment|/* only for sequence constants */
union|union
block|{
name|list
name|u_list
decl_stmt|;
comment|/* ConstructedConstant */
name|char
modifier|*
name|u_value
decl_stmt|;
comment|/* PredefinedConstant */
comment|/* EnumerationConstant */
block|}
name|cn_union
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cn_list
value|cn_union.u_list
end_define

begin_define
define|#
directive|define
name|cn_value
value|cn_union.u_value
end_define

begin_comment
comment|/*  * enumeration definition structure.  */
end_comment

begin_struct
struct|struct
name|enumtag
block|{
name|char
modifier|*
name|en_name
decl_stmt|;
comment|/* C name for this tag */
name|unsigned
name|short
name|en_value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * symbol table structure  */
end_comment

begin_struct
struct|struct
name|symtab
block|{
name|struct
name|object
modifier|*
name|s_syms
decl_stmt|;
name|list
name|s_dependencies
decl_stmt|;
comment|/* a list of modulews */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Kinds of translation functions  */
end_comment

begin_enum
enum|enum
name|translation
block|{
name|EXTERNALIZE
block|,
name|INTERNALIZE
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Predefined types.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|Boolean_type
decl_stmt|,
modifier|*
name|Cardinal_type
decl_stmt|,
modifier|*
name|LongCardinal_type
decl_stmt|,
modifier|*
name|Integer_type
decl_stmt|,
modifier|*
name|LongInteger_type
decl_stmt|,
modifier|*
name|String_type
decl_stmt|,
modifier|*
name|Unspecified_type
decl_stmt|,
modifier|*
name|LongUnspecified_type
decl_stmt|,
modifier|*
name|NilRecord_type
decl_stmt|,
modifier|*
name|StreamEnum_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * symbol table management routines  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|object
modifier|*
name|check_def
argument_list|()
decl_stmt|,
modifier|*
name|make_symbol
argument_list|()
decl_stmt|,
modifier|*
name|make_module
argument_list|()
decl_stmt|,
modifier|*
name|check_dependency
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * routines for entering types in the parse tree  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|make_type
argument_list|()
decl_stmt|,
modifier|*
name|enumeration_type
argument_list|()
decl_stmt|,
modifier|*
name|array_type
argument_list|()
decl_stmt|,
modifier|*
name|sequence_type
argument_list|()
decl_stmt|,
modifier|*
name|record_type
argument_list|()
decl_stmt|,
modifier|*
name|choice_type
argument_list|()
decl_stmt|,
modifier|*
name|procedure_type
argument_list|()
decl_stmt|,
modifier|*
name|error_type
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * routines for entering constants in the parse tree  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|constant
modifier|*
name|Boolean_constant
argument_list|()
decl_stmt|,
modifier|*
name|Numeric_constant
argument_list|()
decl_stmt|,
modifier|*
name|String_constant
argument_list|()
decl_stmt|,
modifier|*
name|array_constant
argument_list|()
decl_stmt|,
modifier|*
name|choice_constant
argument_list|()
decl_stmt|,
modifier|*
name|record_constant
argument_list|()
decl_stmt|,
modifier|*
name|enumeration_constant
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * list headers for all the procedures and errors seen in this module  */
end_comment

begin_decl_stmt
specifier|extern
name|list
name|Procedures
decl_stmt|,
name|Errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * basic lispish functions  */
end_comment

begin_decl_stmt
specifier|extern
name|list
name|cons
argument_list|()
decl_stmt|,
name|nconc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * files we'll be using  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|header
decl_stmt|,
modifier|*
name|header1
decl_stmt|,
modifier|*
name|support1
decl_stmt|,
modifier|*
name|support2
decl_stmt|,
modifier|*
name|client
decl_stmt|,
modifier|*
name|server
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * random global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CurrentProgram
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|object
modifier|*
name|CurrentModule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|CurrentVersion
decl_stmt|,
name|CurrentNumber
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|recursive_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * more functions  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|refstr
argument_list|()
decl_stmt|,
modifier|*
name|xfn
argument_list|()
decl_stmt|,
modifier|*
name|copy
argument_list|()
decl_stmt|,
modifier|*
name|gensym
argument_list|()
decl_stmt|,
modifier|*
name|make_full_name
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

