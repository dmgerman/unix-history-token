begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** symtype.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	symtype.h,v $  * Revision 5.1  91/12/05  07:59:37  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* types related to symbols are defined here */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYMTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|SYMTYPE_H
end_define

begin_comment
comment|/* struct to hold info about builtins */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|PF_CP
name|fp
decl_stmt|;
comment|/* ptr to function that does the builtin */
name|unsigned
name|char
name|min_args
decl_stmt|,
name|max_args
decl_stmt|;
comment|/* info for parser to check correct number of arguments */
block|}
name|BI_REC
typedef|;
end_typedef

begin_comment
comment|/*---------------------------    structures and types for arrays  *--------------------------*/
end_comment

begin_comment
comment|/* array hash nodes */
end_comment

begin_comment
comment|/* string node */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|anode
block|{
name|struct
name|anode
modifier|*
name|link
decl_stmt|,
modifier|*
name|ilink
decl_stmt|;
name|STRING
modifier|*
name|sval
decl_stmt|;
name|int
name|ival
decl_stmt|;
name|CELL
modifier|*
name|cp
decl_stmt|;
block|}
name|ANODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|array
block|{
name|ANODE
modifier|*
name|link
decl_stmt|,
modifier|*
name|ilink
decl_stmt|;
block|}
typedef|*
name|ARRAY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CREATE
value|1
end_define

begin_define
define|#
directive|define
name|NO_CREATE
value|0
end_define

begin_comment
comment|/* note ARRAY is a ptr to a hash table */
end_comment

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|array_find
argument_list|,
operator|(
name|ARRAY
operator|,
name|CELL
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INST
modifier|*
name|PROTO
argument_list|(
name|array_loop
argument_list|,
operator|(
name|INST
operator|*
operator|,
name|CELL
operator|*
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|array_delete
argument_list|,
operator|(
name|ARRAY
operator|,
name|CELL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CELL
modifier|*
name|PROTO
argument_list|(
name|array_cat
argument_list|,
operator|(
name|CELL
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|array_free
argument_list|,
operator|(
name|ARRAY
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|load_array
argument_list|,
operator|(
name|ARRAY
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|new_ARRAY
parameter_list|()
value|(ARRAY)memset(zmalloc(A_HASH_PRIME *\                         sizeof(struct array)),\                         0 , SIZE_T(A_HASH_PRIME*sizeof(struct array)))
end_define

begin_decl_stmt
specifier|extern
name|ARRAY
name|Argv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* struct to hold the state of an array loop */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CELL
modifier|*
name|var
decl_stmt|;
name|ARRAY
name|A
decl_stmt|;
name|int
name|index
decl_stmt|;
comment|/* A[index]  */
name|ANODE
modifier|*
name|ptr
decl_stmt|;
block|}
name|ALOOP_STATE
typedef|;
end_typedef

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|inc_aloop_state
argument_list|,
operator|(
name|ALOOP_STATE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for parsing  (i,j) in A  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|INST
modifier|*
name|start
decl_stmt|;
name|int
name|cnt
decl_stmt|;
block|}
name|ARG2_REC
typedef|;
end_typedef

begin_comment
comment|/*------------------------   user defined functions   ------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fblock
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|INST
modifier|*
name|code
decl_stmt|;
name|unsigned
name|short
name|nargs
decl_stmt|;
name|char
modifier|*
name|typev
decl_stmt|;
comment|/* array of size nargs holding types */
block|}
name|FBLOCK
typedef|;
end_typedef

begin_comment
comment|/* function block */
end_comment

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|add_to_fdump_list
argument_list|,
operator|(
name|FBLOCK
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|fdump
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*-------------------------   elements of the symbol table   -----------------------*/
end_comment

begin_define
define|#
directive|define
name|ST_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ST_VAR
value|1
end_define

begin_define
define|#
directive|define
name|ST_KEYWORD
value|2
end_define

begin_define
define|#
directive|define
name|ST_BUILTIN
value|3
end_define

begin_comment
comment|/* a pointer to a builtin record */
end_comment

begin_define
define|#
directive|define
name|ST_ARRAY
value|4
end_define

begin_comment
comment|/* a void * ptr to a hash table */
end_comment

begin_define
define|#
directive|define
name|ST_FIELD
value|5
end_define

begin_comment
comment|/* a cell ptr to a field */
end_comment

begin_define
define|#
directive|define
name|ST_FUNCT
value|6
end_define

begin_define
define|#
directive|define
name|ST_NR
value|7
end_define

begin_comment
comment|/*  NR is special */
end_comment

begin_define
define|#
directive|define
name|ST_ENV
value|8
end_define

begin_comment
comment|/* and so is ENVIRON */
end_comment

begin_define
define|#
directive|define
name|ST_LOCAL_NONE
value|9
end_define

begin_define
define|#
directive|define
name|ST_LOCAL_VAR
value|10
end_define

begin_define
define|#
directive|define
name|ST_LOCAL_ARRAY
value|11
end_define

begin_define
define|#
directive|define
name|is_local
parameter_list|(
name|stp
parameter_list|)
value|((stp)->type>=ST_LOCAL_NONE)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
name|type
decl_stmt|;
name|unsigned
name|char
name|offset
decl_stmt|;
comment|/* offset in stack frame for local vars */
union|union
block|{
name|CELL
modifier|*
name|cp
decl_stmt|;
name|int
name|kw
decl_stmt|;
name|PF_CP
name|fp
decl_stmt|;
name|BI_REC
modifier|*
name|bip
decl_stmt|;
name|ARRAY
name|array
decl_stmt|;
name|FBLOCK
modifier|*
name|fbp
decl_stmt|;
block|}
name|stval
union|;
block|}
name|SYMTAB
typedef|;
end_typedef

begin_comment
comment|/*****************************  structures for type checking function calls  ******************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ca_rec
block|{
name|struct
name|ca_rec
modifier|*
name|link
decl_stmt|;
name|short
name|type
decl_stmt|;
name|short
name|arg_num
decl_stmt|;
comment|/* position in callee's stack */
comment|/*---------  this data only set if we'll  need to patch -------*/
comment|/* happens if argument is an ID or type ST_NONE or ST_LOCAL_NONE */
name|int
name|call_offset
decl_stmt|;
comment|/* where the type is stored */
name|SYMTAB
modifier|*
name|sym_p
decl_stmt|;
comment|/* if type is ST_NONE  */
name|char
modifier|*
name|type_p
decl_stmt|;
comment|/* if type  is ST_LOCAL_NONE */
block|}
name|CA_REC
typedef|;
end_typedef

begin_comment
comment|/* call argument record */
end_comment

begin_comment
comment|/* type field of CA_REC matches with ST_ types */
end_comment

begin_define
define|#
directive|define
name|CA_EXPR
value|ST_LOCAL_VAR
end_define

begin_define
define|#
directive|define
name|CA_ARRAY
value|ST_LOCAL_ARRAY
end_define

begin_typedef
typedef|typedef
struct|struct
name|fcall
block|{
name|struct
name|fcall
modifier|*
name|link
decl_stmt|;
name|FBLOCK
modifier|*
name|callee
decl_stmt|;
name|short
name|call_scope
decl_stmt|;
name|FBLOCK
modifier|*
name|call
decl_stmt|;
comment|/* only used if call_scope == SCOPE_FUNCT  */
name|INST
modifier|*
name|call_start
decl_stmt|;
comment|/* computed later as code may be moved */
name|CA_REC
modifier|*
name|arg_list
decl_stmt|;
name|short
name|arg_cnt_checked
decl_stmt|;
name|unsigned
name|line_no
decl_stmt|;
comment|/* for error messages */
block|}
name|FCALL_REC
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FCALL_REC
modifier|*
name|resolve_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|resolve_fcalls
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|check_fcall
argument_list|,
operator|(
name|FBLOCK
operator|*
operator|,
name|int
operator|,
name|FBLOCK
operator|*
operator|,
name|CA_REC
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash.c */
end_comment

begin_decl_stmt
name|unsigned
name|PROTO
argument_list|(
name|hash
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMTAB
modifier|*
name|PROTO
argument_list|(
name|insert
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMTAB
modifier|*
name|PROTO
argument_list|(
name|find
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|reverse_find
argument_list|,
operator|(
name|int
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SYMTAB
modifier|*
name|PROTO
argument_list|(
name|save_id
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|restore_ids
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error.c */
end_comment

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|type_error
argument_list|,
operator|(
name|SYMTAB
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMTYPE_H */
end_comment

end_unit

