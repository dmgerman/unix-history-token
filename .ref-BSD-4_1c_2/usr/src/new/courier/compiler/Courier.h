begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|NIL
value|0
end_define

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

begin_comment
comment|/*  * Object classes.  */
end_comment

begin_enum
enum|enum
name|class
block|{
name|O_TYPE
init|=
literal|1
block|,
name|O_CONSTANT
block|,
name|O_SYMBOL
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
name|C_PREDEF
init|=
literal|1
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
comment|/*  * Object structure, for types, numbers, and strings.  */
end_comment

begin_struct
struct|struct
name|object
block|{
name|enum
name|class
name|o_class
decl_stmt|;
union|union
block|{
name|struct
name|type
modifier|*
name|u_type
decl_stmt|;
name|char
modifier|*
name|u_name
decl_stmt|;
name|int
name|u_value
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
name|o_name
value|o_union.u_name
end_define

begin_define
define|#
directive|define
name|o_value
value|o_union.u_value
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
value|(((struct object *) x)->o_value)
end_define

begin_comment
comment|/*  * Type structure.  *  * Formats of various lists are as follows.  * . indicates a cons operation.  * ... indicates a list of elements of the preceding form.  *  * enumeration:  *	((name . value) ...)  * record, error, procedure arguments, procedure results:  *	(((name ...) . type) ...)  * choice:  *	((((name . value) ...) . type) ...)  */
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
union|union
block|{
name|list
name|u_list
decl_stmt|;
comment|/* enumeration, record, error */
struct|struct
block|{
name|struct
name|object
modifier|*
name|u_size
decl_stmt|,
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
name|object
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
comment|/*  * This macro is to cope with the fact that C passes arrays  * by reference but all other constructed types by value.  */
end_comment

begin_define
define|#
directive|define
name|refstr
parameter_list|(
name|t
parameter_list|)
value|(basetype(t)->t_constr == C_ARRAY ? "" : "&")
end_define

begin_comment
comment|/*  * Predefined types.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|object
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|object
modifier|*
name|Undefined_constant
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|object
modifier|*
name|make
argument_list|()
decl_stmt|,
modifier|*
name|lookup
argument_list|()
decl_stmt|,
modifier|*
name|basetype
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|object
modifier|*
name|construct_type1
argument_list|()
decl_stmt|,
modifier|*
name|construct_type2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|object
modifier|*
name|construct_choice
argument_list|()
decl_stmt|,
modifier|*
name|construct_procedure
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|list
name|Values
decl_stmt|,
name|Types
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|hf
decl_stmt|,
modifier|*
name|cf1
decl_stmt|,
modifier|*
name|cf2
decl_stmt|,
modifier|*
name|uf
decl_stmt|,
modifier|*
name|sf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|explicit
decl_stmt|,
name|print_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|copy
argument_list|()
decl_stmt|,
modifier|*
name|gensym
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|obj_rep
argument_list|()
decl_stmt|,
modifier|*
name|pack_function
argument_list|()
decl_stmt|,
modifier|*
name|unpack_function
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

