begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Fundamental definitions for GNU Emacs Lisp interpreter.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* Define the fundamental Lisp data structures */
end_comment

begin_comment
comment|/* This is the set of Lisp data types */
end_comment

begin_enum
enum|enum
name|Lisp_Type
block|{
comment|/* Integer.  object.v.integer is the integer value. */
name|Lisp_Int
block|,
comment|/* Symbol.  object.v.symbol points to a struct Lisp_Symbol. */
name|Lisp_Symbol
block|,
comment|/* Marker (editor pointer).  object.v.marker points to a struct Lisp_Marker. */
name|Lisp_Marker
block|,
comment|/* String.  object.v.string points to a struct Lisp_String.        The length of the string, and its contents, are stored therein. */
name|Lisp_String
block|,
comment|/* Vector of Lisp objects.  object.v.vector points to a struct Lisp_Vector.        The length of the vector, and its contents, are stored therein. */
name|Lisp_Vector
block|,
comment|/* Cons.  object.v.cons points to a struct Lisp_Cons. */
name|Lisp_Cons
block|,
comment|/* Treated like vector in GC, except do not set its mark bit.        Used for internal data blocks that will be explicitly freed        but which, while active, are reached by GC mark exactly once        and should be marked through like a vector.  */
name|Lisp_Temp_Vector
block|,
comment|/* Editor buffer.  obj.v.buffer points to a struct buffer.        No buffer is ever truly freed; they can be "killed", but this        just marks them as dead. */
name|Lisp_Buffer
block|,
comment|/* Built-in function.  obj.v.subr points to a struct Lisp_Subr        which describes how to call the function, and its documentation,        as well as pointing to the code. */
name|Lisp_Subr
block|,
comment|/* Internal value return by subroutines of read.        The user never sees this data type.        Its value is just a number. */
name|Lisp_Internal
block|,
comment|/* Forwarding pointer to an int variable.        This is allowed only in the value cell of a symbol,        and it means that the symbol's value really lives in the        specified int variable.        obj.v.intptr points to the int variable. */
name|Lisp_Intfwd
block|,
comment|/* Boolean forwarding pointer to an int variable.        This is like Lisp_Intfwd except that the ostensible "value" of the symbol        is t if the int variable is nonzero, nil if it is zero.        obj.v.intptr points to the int variable. */
name|Lisp_Boolfwd
block|,
comment|/* Object describing a connection to a subprocess.        It points to storage of type  struct Lisp_Process  */
name|Lisp_Process
block|,
comment|/* Forwarding pointer to a Lisp_Object variable.        This is allowed only in the value cell of a symbol,        and it means that the symbol's value really lives in the        specified variable.        obj.v.objfwd points to the Lisp_Object variable. */
name|Lisp_Objfwd
block|,
comment|/* Used when the core address of a function needs to be passed        in an argument of type Lisp_Object.        obj.v.function is the pointer-to-function.        The user will never see this data type. */
name|Lisp_Internal_Function
block|,
comment|/* Used when a FILE * value needs to be passed        in an argument of type Lisp_Object.        You must do (FILE *) obj.v.integer to get the value.        The user will never see this data type. */
name|Lisp_Internal_Stream
block|,
comment|/* Used in a symbol value cell when the symbol's value is per-buffer.         The actual contents are a cons cell which starts a list like this:         (REALVALUE BUFFER CURRENT-ALIST-ELEMENT . DEFAULT-VALUE)).  	BUFFER is the last buffer for which this symbol's value was 	made up to date.          CURRENT-ALIST-ELEMENT is a pointer to an element of BUFFER's 	b_local_var_alist, that being the element whose car is this variable.         Or it can be a pointer to the (CURRENT-ALIST-ELEMENT . DEFAULT-VALUE), if BUFFER 	does not have an element in its alist for this variable 	(that is, if BUFFER sees the default value of this variable).  	If we want to examine or set the value and BUFFER is current, 	we just examine or set REALVALUE. 	If BUFFER is not current, we store the current REALVALUE value into 	CURRENT-ALIST-ELEMENT, then find the appropriate alist element for 	the buffer now current and set up CURRENT-ALIST-ELEMENT. 	Then we set REALVALUE out of that element, and store into BUFFER.  	If we are setting the variable and the current buffer does not have 	an alist entry for this variable, an alist entry is created.  	Note that REALVALUE can be a forwarding pointer. 	Each time it is examined or set, forwarding must be done.  */
name|Lisp_Buffer_Local_Value
block|,
comment|/* Like Lisp_Buffer_Local_Value with one difference: 	merely setting the variable while some buffer is current 	does not cause that buffer to have its own local value of this variable. 	Only make-local-variable does that.  */
name|Lisp_Some_Buffer_Local_Value
block|,
comment|/* Like Lisp_Objfwd except that value lives in a slot        in the current buffer.  Value is byte index of slot within buffer */
name|Lisp_Buffer_Objfwd
block|,
comment|/* In symbol value cell, means var is unbound.        In symbol function cell, means function name is undefined. */
name|Lisp_Void
block|,
comment|/* Window used for Emacs display.        Data inside looks like a Lisp_Vector.  */
name|Lisp_Window
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNION_TYPE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_comment
comment|/* Definition of Lisp_Object for little-endian machines.  */
end_comment

begin_typedef
typedef|typedef
union|union
name|Lisp_Object
block|{
comment|/* Used for comparing two Lisp_Objects;        also, positive integers can be accessed fast this way. */
name|int
name|i
decl_stmt|;
struct|struct
block|{
name|int
name|val
range|:
literal|24
decl_stmt|;
name|char
name|type
decl_stmt|;
block|}
name|s
struct|;
struct|struct
block|{
name|unsigned
name|int
name|val
range|:
literal|24
decl_stmt|;
name|char
name|type
decl_stmt|;
block|}
name|u
struct|;
struct|struct
block|{
name|unsigned
name|int
name|val
range|:
literal|24
decl_stmt|;
name|enum
name|Lisp_Type
name|type
range|:
literal|7
decl_stmt|;
comment|/* The markbit is not really part of the value of a Lisp_Object, 	   and is always zero except during garbage collection.  */
name|unsigned
name|int
name|markbit
range|:
literal|1
decl_stmt|;
block|}
name|gu
struct|;
block|}
name|Lisp_Object
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* If BIG_ENDIAN */
end_comment

begin_typedef
typedef|typedef
union|union
name|Lisp_Object
block|{
comment|/* Used for comparing two Lisp_Objects;        also, positive integers can be accessed fast this way. */
name|int
name|i
decl_stmt|;
struct|struct
block|{
name|char
name|type
decl_stmt|;
name|int
name|val
range|:
literal|24
decl_stmt|;
block|}
name|s
struct|;
struct|struct
block|{
name|char
name|type
decl_stmt|;
name|unsigned
name|int
name|val
range|:
literal|24
decl_stmt|;
block|}
name|u
struct|;
struct|struct
block|{
comment|/* The markbit is not really part of the value of a Lisp_Object, 	   and is always zero except during garbage collection.  */
name|unsigned
name|int
name|markbit
range|:
literal|1
decl_stmt|;
name|enum
name|Lisp_Type
name|type
range|:
literal|7
decl_stmt|;
name|unsigned
name|int
name|val
range|:
literal|24
decl_stmt|;
block|}
name|gu
struct|;
block|}
name|Lisp_Object
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
endif|BIG_ENDIAN
end_endif

begin_endif
endif|#
directive|endif
endif|NO_UNION_TYPE
end_endif

begin_comment
comment|/* If union type is not wanted, define Lisp_Object as just a number    and define the macros below to extract fields by shifting */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_UNION_TYPE
end_ifdef

begin_define
define|#
directive|define
name|Lisp_Object
value|int
end_define

begin_comment
comment|/* These values are overridden by the m- file on some machines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALBITS
end_ifndef

begin_define
define|#
directive|define
name|VALBITS
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GCTYPEBITS
end_ifndef

begin_define
define|#
directive|define
name|GCTYPEBITS
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VALMASK
value|((1<<VALBITS) - 1)
end_define

begin_define
define|#
directive|define
name|GCTYPEMASK
value|((1<<GCTYPEBITS) - 1)
end_define

begin_define
define|#
directive|define
name|MARKBIT
value|(1<< (VALBITS + GCTYPEBITS))
end_define

begin_endif
endif|#
directive|endif
endif|NO_UNION_TYPE
end_endif

begin_escape
end_escape

begin_comment
comment|/* These macros extract various sorts of values from a Lisp_Object.  For example, if tem is a Lisp_Object whose type is Lisp_Cons,  XCONS (tem) is the struct Lisp_Cons * pointing to the memory for that cons. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_UNION_TYPE
end_ifdef

begin_define
define|#
directive|define
name|XTYPE
parameter_list|(
name|a
parameter_list|)
value|((enum Lisp_Type) ((a)>> VALBITS))
end_define

begin_define
define|#
directive|define
name|XSETTYPE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)  =  ((a)& VALMASK)  +  ((int)(b)<< VALBITS))
end_define

begin_comment
comment|/* Use XFASTINT for fast retrieval and storage of integers known   to be positive.  This takes advantage of the fact that Lisp_Int is 0.  */
end_comment

begin_define
define|#
directive|define
name|XFASTINT
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|XINT
parameter_list|(
name|a
parameter_list|)
value|(((a)<< INTBITS-VALBITS)>> INTBITS-VALBITS)
end_define

begin_define
define|#
directive|define
name|XUINT
parameter_list|(
name|a
parameter_list|)
value|((a)& VALMASK)
end_define

begin_define
define|#
directive|define
name|XSETINT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) = ((a)& ~VALMASK)  +  ((b)& VALMASK))
end_define

begin_define
define|#
directive|define
name|XSETUINT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) = ((a)& ~VALMASK)  +  ((b)& VALMASK))
end_define

begin_define
define|#
directive|define
name|XSET
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|ptr
parameter_list|)
define|\
value|((var) = ((int)(type)<< VALBITS) + ((int) (ptr)& VALMASK))
end_define

begin_comment
comment|/* During garbage collection, XGCTYPE must be used for extracting types  so that the mark bit is ignored.  XMARKBIT access the markbit.  Markbits are used only in particular slots of particular structure types.  Other markbits are always zero.  Outside of garbage collection, all mark bits are always zero.  */
end_comment

begin_define
define|#
directive|define
name|XGCTYPE
parameter_list|(
name|a
parameter_list|)
value|((enum Lisp_Type) (((a)>> VALBITS)& GCTYPEMASK))
end_define

begin_define
define|#
directive|define
name|XMARKBIT
parameter_list|(
name|a
parameter_list|)
value|((a)& MARKBIT)
end_define

begin_define
define|#
directive|define
name|XSETMARKBIT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) = ((a)& ~MARKBIT) + (b))
end_define

begin_define
define|#
directive|define
name|XMARK
parameter_list|(
name|a
parameter_list|)
value|((a) |= MARKBIT)
end_define

begin_define
define|#
directive|define
name|XUNMARK
parameter_list|(
name|a
parameter_list|)
value|((a)&= ~MARKBIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNION_TYPE
end_ifndef

begin_define
define|#
directive|define
name|XTYPE
parameter_list|(
name|a
parameter_list|)
value|((enum Lisp_Type) (a).u.type)
end_define

begin_define
define|#
directive|define
name|XSETTYPE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a).u.type = (char) (b))
end_define

begin_comment
comment|/* Use XFASTINT for fast retrieval and storage of integers known   to be positive.  This takes advantage of the fact that Lisp_Int is 0.  */
end_comment

begin_define
define|#
directive|define
name|XFASTINT
parameter_list|(
name|a
parameter_list|)
value|((a).i)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EXPLICIT_SIGN_EXTEND
end_ifdef

begin_comment
comment|/* Make sure we sign-extend; compilers have been known to fail to do so.  */
end_comment

begin_define
define|#
directive|define
name|XINT
parameter_list|(
name|a
parameter_list|)
value|(((a).i<< 8)>> 8)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XINT
parameter_list|(
name|a
parameter_list|)
value|((a).s.val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XUINT
parameter_list|(
name|a
parameter_list|)
value|((a).u.val)
end_define

begin_define
define|#
directive|define
name|XSETINT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a).s.val = (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETUINT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a).s.val = (int) (b))
end_define

begin_define
define|#
directive|define
name|XSET
parameter_list|(
name|var
parameter_list|,
name|vartype
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(((var).s.type = ((char) (vartype))), ((var).s.val = ((int) (ptr))))
end_define

begin_comment
comment|/* During garbage collection, XGCTYPE must be used for extracting types  so that the mark bit is ignored.  XMARKBIT access the markbit.  Markbits are used only in particular slots of particular structure types.  Other markbits are always zero.  Outside of garbage collection, all mark bits are always zero.  */
end_comment

begin_define
define|#
directive|define
name|XGCTYPE
parameter_list|(
name|a
parameter_list|)
value|((a).gu.type)
end_define

begin_define
define|#
directive|define
name|XMARKBIT
parameter_list|(
name|a
parameter_list|)
value|((a).gu.markbit)
end_define

begin_define
define|#
directive|define
name|XSETMARKBIT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(XMARKBIT(a) = (b))
end_define

begin_define
define|#
directive|define
name|XMARK
parameter_list|(
name|a
parameter_list|)
value|(XMARKBIT(a) = 1)
end_define

begin_define
define|#
directive|define
name|XUNMARK
parameter_list|(
name|a
parameter_list|)
value|(XMARKBIT(a) = 0)
end_define

begin_endif
endif|#
directive|endif
endif|NO_UNION_TYPE
end_endif

begin_define
define|#
directive|define
name|XCONS
parameter_list|(
name|a
parameter_list|)
value|((struct Lisp_Cons *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XBUFFER
parameter_list|(
name|a
parameter_list|)
value|((struct buffer *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XVECTOR
parameter_list|(
name|a
parameter_list|)
value|((struct Lisp_Vector *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XSUBR
parameter_list|(
name|a
parameter_list|)
value|((struct Lisp_Subr *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XSTRING
parameter_list|(
name|a
parameter_list|)
value|((struct Lisp_String *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XSYMBOL
parameter_list|(
name|a
parameter_list|)
value|((struct Lisp_Symbol *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XFUNCTION
parameter_list|(
name|a
parameter_list|)
value|((Lisp_Object (*)()) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XMARKER
parameter_list|(
name|a
parameter_list|)
value|((struct Lisp_Marker *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XOBJFWD
parameter_list|(
name|a
parameter_list|)
value|((Lisp_Object *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XINTPTR
parameter_list|(
name|a
parameter_list|)
value|((int *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XWINDOW
parameter_list|(
name|a
parameter_list|)
value|((struct window *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XPROCESS
parameter_list|(
name|a
parameter_list|)
value|((struct Lisp_Process *) XUINT(a))
end_define

begin_define
define|#
directive|define
name|XSETCONS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETBUFFER
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETVECTOR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETSUBR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETSTRING
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETSYMBOL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETFUNCTION
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETMARKER
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETOBJFWD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETINTPTR
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETWINDOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_define
define|#
directive|define
name|XSETPROCESS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XSETUINT(a, (int) (b))
end_define

begin_escape
end_escape

begin_comment
comment|/* In a cons, the markbit of the car is the gc mark bit */
end_comment

begin_struct
struct|struct
name|Lisp_Cons
block|{
name|Lisp_Object
name|car
decl_stmt|,
name|cdr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Like a cons, but records info on where the text lives that it was read from */
end_comment

begin_comment
comment|/* This is not really in use now */
end_comment

begin_struct
struct|struct
name|Lisp_Buffer_Cons
block|{
name|Lisp_Object
name|car
decl_stmt|,
name|cdr
decl_stmt|;
name|struct
name|buffer
modifier|*
name|buffer
decl_stmt|;
name|int
name|bufpos
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* In a string or vector, the sign bit of the `size' is the gc mark bit */
end_comment

begin_struct
struct|struct
name|Lisp_String
block|{
name|int
name|size
decl_stmt|;
name|unsigned
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Lisp_Vector
block|{
name|int
name|size
decl_stmt|;
name|struct
name|Lisp_Vector
modifier|*
name|next
decl_stmt|;
name|Lisp_Object
name|contents
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* In a symbol, the markbit of the plist is used as the gc mark bit */
end_comment

begin_struct
struct|struct
name|Lisp_Symbol
block|{
name|struct
name|Lisp_String
modifier|*
name|name
decl_stmt|;
name|Lisp_Object
name|value
decl_stmt|;
name|Lisp_Object
name|function
decl_stmt|;
name|Lisp_Object
name|plist
decl_stmt|;
name|struct
name|Lisp_Symbol
modifier|*
name|next
decl_stmt|;
comment|/* -> next symbol in this obarray bucket */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Lisp_Subr
block|{
name|Lisp_Object
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|()
function_decl|;
name|short
name|min_args
decl_stmt|,
name|max_args
decl_stmt|;
name|char
modifier|*
name|symbol_name
decl_stmt|;
name|char
modifier|*
name|prompt
decl_stmt|;
name|char
modifier|*
name|doc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* In a marker, the markbit of the chain field is used as the gc mark bit */
end_comment

begin_struct
struct|struct
name|Lisp_Marker
block|{
name|struct
name|buffer
modifier|*
name|buffer
decl_stmt|;
name|Lisp_Object
name|chain
decl_stmt|;
name|int
name|bufpos
decl_stmt|;
name|int
name|modified
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* Data type checking */
end_comment

begin_define
define|#
directive|define
name|NULL
parameter_list|(
name|x
parameter_list|)
value|(XFASTINT (x) == XFASTINT (Qnil))
end_define

begin_define
define|#
directive|define
name|LISTP
parameter_list|(
name|x
parameter_list|)
value|(XTYPE ((x)) == Lisp_Cons)
end_define

begin_define
define|#
directive|define
name|EQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(XFASTINT (x) == XFASTINT (y))
end_define

begin_define
define|#
directive|define
name|CHECK_STRING
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_String) x = wrong_type_argument (Qstringp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_SYMBOL
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_Symbol) x = wrong_type_argument (Qsymbolp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_VECTOR
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_Vector) x = wrong_type_argument (Qvectorp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_BUFFER
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_Buffer) x = wrong_type_argument (Qbufferp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_WINDOW
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_Window) x = wrong_type_argument (Qwindowp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_PROCESS
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_Process) x = wrong_type_argument (Qprocessp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_NUMBER
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_Int) x = wrong_type_argument (Qintegerp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_MARKER
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) != Lisp_Marker) x = wrong_type_argument (Qmarkerp, (x)); }
end_define

begin_define
define|#
directive|define
name|CHECK_NUMBER_COERCE_MARKER
parameter_list|(
name|x
parameter_list|,
name|i
parameter_list|)
define|\
value|{ if (XTYPE ((x)) == Lisp_Marker) XFASTINT (x) = marker_position (x); \     else if (XTYPE ((x)) != Lisp_Int) x = wrong_type_argument (Qinteger_or_marker_p, (x)); }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VIRT_ADDR_VARIES
end_ifdef

begin_comment
comment|/* For machines like APOLLO where text and data can go anywhere    in virtual memory.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_IMPURE
parameter_list|(
name|obj
parameter_list|)
define|\
value|{ extern int pure[]; \     if (XUINT (obj)< (int) ((char *) pure + PURESIZE) \&& XUINT (obj)>= (int) pure) \       pure_write_error (); }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not VIRT_ADDR_VARIES */
end_comment

begin_define
define|#
directive|define
name|CHECK_IMPURE
parameter_list|(
name|obj
parameter_list|)
define|\
value|{ extern int my_edata; \     if (XUINT (obj)< (unsigned int)&my_edata) \       pure_write_error (); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not VIRT_ADDR_VARIES */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Define a built-in function for calling from Lisp.  `lname' should be the name to give the function in Lisp,     as a null-terminated C string.  `fnname' should be the name of the function in C.     By convention, it starts with F.  `sname' should be the name for the C constant structure     that records information on this function for internal use.     By convention, it should be the same as `fnname' but with S instead of F.     It's too bad that C macros can't compute this from `fnname'.  `minargs' should be a number, the minimum number of arguments allowed.  `maxargs' should be a number, the maximum number of arguments allowed,     or else MANY or UNEVALLED.     MANY means pass a vector of evaluated arguments, 	 in the form of an integer number-of-arguments 	 followed by the address of a vector of Lisp_Objects 	 which contains the argument values.     UNEVALLED means pass the list of unevaluated arguments  `prompt' says how to read arguments for an interactive call.     This can be zero or a C string.     Zero means that interactive calls are not allowed.     A string is interpreted in a hairy way:      it should contain one line for each argument to be read, terminated by \n.      The first character of the line controls the type of parsing:        s  --  read a string.        S  --  read a symbol.        k  --  read a key sequence and return it as a string.        a  --  read a function name (symbol) with completion.        C  --  read a command name (symbol) with completion.        v  --  read a variable name (symbol) with completion.        b  --  read a buffer name (a string) with completion.        B  --  buffer name, may be existing buffer or may not be.        f  --  read a file name, file must exist.        F  --  read a file name, file need not exist.        n  --  read a number.        c  --  read a character and return it as a number.        p  --  use the numeric value of the prefix argument.        P  --  use raw value of prefix - can be nil, -, (NUMBER) or NUMBER.        x  --  read a Lisp object from the minibuffer.        X  --  read a Lisp form from the minibuffer and use its value.     A null string means call interactively with no arguments.  `doc' is documentation for the user. */
end_comment

begin_define
define|#
directive|define
name|DEFUN
parameter_list|(
name|lname
parameter_list|,
name|fnname
parameter_list|,
name|sname
parameter_list|,
name|minargs
parameter_list|,
name|maxargs
parameter_list|,
name|prompt
parameter_list|,
name|doc
parameter_list|)
define|\
value|Lisp_Object fnname (); \   struct Lisp_Subr sname = {fnname, minargs, maxargs, lname, prompt, 0}; \   Lisp_Object fnname
end_define

begin_comment
comment|/* defsubr (Sname);  is how we define the symbol for function `name' at start-up time. */
end_comment

begin_function_decl
specifier|extern
name|void
name|defsubr
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MANY
value|-2
end_define

begin_define
define|#
directive|define
name|UNEVALLED
value|-1
end_define

begin_define
define|#
directive|define
name|DEFSIMPLE
parameter_list|(
name|lname
parameter_list|,
name|fnname
parameter_list|,
name|sname
parameter_list|,
name|doc
parameter_list|,
name|valtype
parameter_list|,
name|setcomp
parameter_list|,
name|exp
parameter_list|)
define|\
value|DEFUN (lname, fnname, sname, 0, 0, 0, 0) () \   { \     Lisp_Object val; \     XSET (val, valtype, exp); \     return val; }
end_define

begin_define
define|#
directive|define
name|DEFPRED
parameter_list|(
name|lname
parameter_list|,
name|fnname
parameter_list|,
name|sname
parameter_list|,
name|doc
parameter_list|,
name|boolexp
parameter_list|)
define|\
value|DEFUN (lname, fnname, sname, 0, 0, 0, 0) () \   { if (boolexp) return Qt; return Qnil; }
end_define

begin_escape
end_escape

begin_comment
comment|/* Structure for recording Lisp call stack for backtrace purposes */
end_comment

begin_struct
struct|struct
name|specbinding
block|{
name|Lisp_Object
name|symbol
decl_stmt|,
name|old_value
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|specbinding
modifier|*
name|specpdl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|specbinding
modifier|*
name|specpdl_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|specpdl_size
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|handler
block|{
name|Lisp_Object
name|handler
decl_stmt|;
name|Lisp_Object
name|var
decl_stmt|;
name|struct
name|catchtag
modifier|*
name|tag
decl_stmt|;
name|struct
name|handler
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|handler
modifier|*
name|handlerlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check quit-flag and quit if it is non-nil. */
end_comment

begin_define
define|#
directive|define
name|QUIT
define|\
value|if (!NULL (Vquit_flag)&& NULL (Vinhibit_quit)) \     { Vquit_flag = Qnil; Fsignal (Qquit, Qnil); }
end_define

begin_escape
end_escape

begin_comment
comment|/* number of bytes of structure consed since last GC */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|consing_since_gc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* threshold for doing another gc */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gc_cons_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Structure for recording stack slots that need marking */
end_comment

begin_comment
comment|/* This is a chain of structures, each of which points at a Lisp_Object variable  whose value should be marked in garbage collection.  Normally every link of the chain is an automatic variable of a function,  and its `val' points to some argument or local variable of the function.  On exit to the function, the chain is set back to the value it had on entry.  This way, no link remains in the chain when the stack frame containing the link disappears.   Every function that can call Feval must protect in this fashion all  Lisp_Object variables whose contents will be used again. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gcpro
modifier|*
name|gcprolist
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|gcpro
block|{
name|struct
name|gcpro
modifier|*
name|next
decl_stmt|;
name|Lisp_Object
modifier|*
name|var
decl_stmt|;
comment|/* Address of first protected variable */
name|int
name|nvars
decl_stmt|;
comment|/* Number of consecutive protected variables */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GCPRO1
parameter_list|(
name|varname
parameter_list|)
define|\
value|{gcpro1.next = gcprolist; gcpro1.var =&varname; gcpro1.nvars = 1; \   gcprolist =&gcpro1; }
end_define

begin_define
define|#
directive|define
name|GCPRO2
parameter_list|(
name|varname1
parameter_list|,
name|varname2
parameter_list|)
define|\
value|{gcpro1.next = gcprolist; gcpro1.var =&varname1; gcpro1.nvars = 1; \   gcpro2.next =&gcpro1; gcpro2.var =&varname2; gcpro2.nvars = 1; \   gcprolist =&gcpro2; }
end_define

begin_define
define|#
directive|define
name|GCPRO3
parameter_list|(
name|varname1
parameter_list|,
name|varname2
parameter_list|,
name|varname3
parameter_list|)
define|\
value|{gcpro1.next = gcprolist; gcpro1.var =&varname1; gcpro1.nvars = 1; \   gcpro2.next =&gcpro1; gcpro2.var =&varname2; gcpro2.nvars = 1; \   gcpro3.next =&gcpro2; gcpro3.var =&varname3; gcpro3.nvars = 1; \   gcprolist =&gcpro3; }
end_define

begin_define
define|#
directive|define
name|GCPRO4
parameter_list|(
name|varname1
parameter_list|,
name|varname2
parameter_list|,
name|varname3
parameter_list|,
name|varname4
parameter_list|)
define|\
value|{gcpro1.next = gcprolist; gcpro1.var =&varname1; gcpro1.nvars = 1; \   gcpro2.next =&gcpro1; gcpro2.var =&varname2; gcpro2.nvars = 1; \   gcpro3.next =&gcpro2; gcpro3.var =&varname3; gcpro3.nvars = 1; \   gcpro4.next =&gcpro3; gcpro4.var =&varname4; gcpro4.nvars = 1; \   gcprolist =&gcpro4; }
end_define

begin_comment
comment|/* Call staticpro (&var) to protect static variable `var'. */
end_comment

begin_function_decl
name|void
name|staticpro
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UNGCPRO
value|(gcprolist = gcpro1.next)
end_define

begin_escape
end_escape

begin_comment
comment|/* Defined in data.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qnil
decl_stmt|,
name|Qt
decl_stmt|,
name|Qquote
decl_stmt|,
name|Qlambda
decl_stmt|,
name|Qsubr
decl_stmt|,
name|Qunbound
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qerror_conditions
decl_stmt|,
name|Qerror_message
decl_stmt|,
name|Qtop_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qerror
decl_stmt|,
name|Qquit
decl_stmt|,
name|Qwrong_type_argument
decl_stmt|,
name|Qargs_out_of_range
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qvoid_variable
decl_stmt|,
name|Qvoid_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qsetting_constant
decl_stmt|,
name|Qinvalid_read_syntax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qinvalid_function
decl_stmt|,
name|Qwrong_number_of_arguments
decl_stmt|,
name|Qno_catch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qend_of_file
decl_stmt|,
name|Qarith_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qbeginning_of_buffer
decl_stmt|,
name|Qend_of_buffer
decl_stmt|,
name|Qbuffer_read_only
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qintegerp
decl_stmt|,
name|Qnatnump
decl_stmt|,
name|Qsymbolp
decl_stmt|,
name|Qlistp
decl_stmt|,
name|Qconsp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qstringp
decl_stmt|,
name|Qarrayp
decl_stmt|,
name|Qsequencep
decl_stmt|,
name|Qbufferp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qchar_or_string_p
decl_stmt|,
name|Qmarkerp
decl_stmt|,
name|Qvectorp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qinteger_or_marker_p
decl_stmt|,
name|Qboundp
decl_stmt|,
name|Qfboundp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qcdr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Feq
argument_list|()
decl_stmt|,
name|Fnull
argument_list|()
decl_stmt|,
name|Flistp
argument_list|()
decl_stmt|,
name|Fconsp
argument_list|()
decl_stmt|,
name|Fatom
argument_list|()
decl_stmt|,
name|Fnlistp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fintegerp
argument_list|()
decl_stmt|,
name|Fnatnump
argument_list|()
decl_stmt|,
name|Fsymbolp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fvectorp
argument_list|()
decl_stmt|,
name|Fstringp
argument_list|()
decl_stmt|,
name|Farrayp
argument_list|()
decl_stmt|,
name|Fsequencep
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fbufferp
argument_list|()
decl_stmt|,
name|Fmarkerp
argument_list|()
decl_stmt|,
name|Fsubrp
argument_list|()
decl_stmt|,
name|Fchar_or_string_p
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Finteger_or_marker_p
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fcar
argument_list|()
decl_stmt|,
name|Fcar_safe
argument_list|()
decl_stmt|,
name|Fcdr
argument_list|()
decl_stmt|,
name|Fcdr_safe
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fsetcar
argument_list|()
decl_stmt|,
name|Fsetcdr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fboundp
argument_list|()
decl_stmt|,
name|Ffboundp
argument_list|()
decl_stmt|,
name|Fmakunbound
argument_list|()
decl_stmt|,
name|Ffmakunbound
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fsymbol_function
argument_list|()
decl_stmt|,
name|Fsymbol_plist
argument_list|()
decl_stmt|,
name|Fsymbol_name
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Ffset
argument_list|()
decl_stmt|,
name|Fsetplist
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fsymbol_value
argument_list|()
decl_stmt|,
name|Fset
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fdefault_value
argument_list|()
decl_stmt|,
name|Fset_default
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Faref
argument_list|()
decl_stmt|,
name|Faset
argument_list|()
decl_stmt|,
name|Farray_length
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fstring_to_int
argument_list|()
decl_stmt|,
name|Fint_to_string
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Feqlsign
argument_list|()
decl_stmt|,
name|Fgtr
argument_list|()
decl_stmt|,
name|Flss
argument_list|()
decl_stmt|,
name|Fgeq
argument_list|()
decl_stmt|,
name|Fleq
argument_list|()
decl_stmt|,
name|Fneq
argument_list|()
decl_stmt|,
name|Fzerop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fplus
argument_list|()
decl_stmt|,
name|Fminus
argument_list|()
decl_stmt|,
name|Ftimes
argument_list|()
decl_stmt|,
name|Fquo
argument_list|()
decl_stmt|,
name|Frem
argument_list|()
decl_stmt|,
name|Fmax
argument_list|()
decl_stmt|,
name|Fmin
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Flogand
argument_list|()
decl_stmt|,
name|Flogior
argument_list|()
decl_stmt|,
name|Flogxor
argument_list|()
decl_stmt|,
name|Flognot
argument_list|()
decl_stmt|,
name|Flsh
argument_list|()
decl_stmt|,
name|Fash
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fadd1
argument_list|()
decl_stmt|,
name|Fsub1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|make_number
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|wrong_type_argument
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in fns.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qstring_lessp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vfeatures
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fidentity
argument_list|()
decl_stmt|,
name|Frandom
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Flength
argument_list|()
decl_stmt|,
name|Fstring_equal
argument_list|()
decl_stmt|,
name|Fstring_lessp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fappend
argument_list|()
decl_stmt|,
name|Fconcat
argument_list|()
decl_stmt|,
name|Fvconcat
argument_list|()
decl_stmt|,
name|Fcopy_sequence
argument_list|()
decl_stmt|,
name|Fsubstring
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fnth
argument_list|()
decl_stmt|,
name|Fnthcdr
argument_list|()
decl_stmt|,
name|Fmemq
argument_list|()
decl_stmt|,
name|Fassq
argument_list|()
decl_stmt|,
name|Fassoc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Frassq
argument_list|()
decl_stmt|,
name|Fdelq
argument_list|()
decl_stmt|,
name|Fsort
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Freverse
argument_list|()
decl_stmt|,
name|Fnreverse
argument_list|()
decl_stmt|,
name|Fget
argument_list|()
decl_stmt|,
name|Fput
argument_list|()
decl_stmt|,
name|Fequal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Ffillarray
argument_list|()
decl_stmt|,
name|Fnconc
argument_list|()
decl_stmt|,
name|Fmapcar
argument_list|()
decl_stmt|,
name|Fmapconcat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fy_or_n_p
argument_list|()
decl_stmt|,
name|Fyes_or_no_p
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Ffeaturep
argument_list|()
decl_stmt|,
name|Frequire
argument_list|()
decl_stmt|,
name|Fprovide
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|concat2
argument_list|()
decl_stmt|,
name|nconc2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in alloc.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vpurify_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fcons
argument_list|()
decl_stmt|,
name|Flist
argument_list|()
decl_stmt|,
name|Fmake_list
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fmake_vector
argument_list|()
decl_stmt|,
name|Fvector
argument_list|()
decl_stmt|,
name|Fmake_symbol
argument_list|()
decl_stmt|,
name|Fmake_marker
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fmake_string
argument_list|()
decl_stmt|,
name|build_string
argument_list|()
decl_stmt|,
name|make_string
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fpurecopy
argument_list|()
decl_stmt|,
name|make_pure_string
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|pure_cons
argument_list|()
decl_stmt|,
name|make_pure_vector
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fgarbage_collect
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in print.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vprin1_to_string_buffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fprin1
argument_list|()
decl_stmt|,
name|Fprin1_to_string
argument_list|()
decl_stmt|,
name|Fprinc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fterpri
argument_list|()
decl_stmt|,
name|Fprint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vstandard_output
decl_stmt|,
name|Qstandard_output
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern temp_output_buffer_setup (
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|temp_output_buffer_show
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Defined in read.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qvariable_documentation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vobarray
decl_stmt|,
name|Vstandard_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fread
argument_list|()
decl_stmt|,
name|Fread_from_string
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fintern
argument_list|()
decl_stmt|,
name|Fintern_soft
argument_list|()
decl_stmt|,
name|Fload
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fget_file_char
argument_list|()
decl_stmt|,
name|Fread_char
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Feval_current_buffer
argument_list|()
decl_stmt|,
name|Feval_region
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|intern
argument_list|()
decl_stmt|,
name|oblookup
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in eval.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qautoload
decl_stmt|,
name|Qexit
decl_stmt|,
name|Qinteractive
decl_stmt|,
name|Qcommandp
decl_stmt|,
name|Qdefun
decl_stmt|,
name|Qmacro
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vinhibit_quit
decl_stmt|,
name|Vquit_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vmocklisp_arguments
decl_stmt|,
name|Qmocklisp
decl_stmt|,
name|Qmocklisp_arguments
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vautoload_queue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fand
argument_list|()
decl_stmt|,
name|For
argument_list|()
decl_stmt|,
name|Fif
argument_list|()
decl_stmt|,
name|Fprogn
argument_list|()
decl_stmt|,
name|Fprog1
argument_list|()
decl_stmt|,
name|Fprog2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fsetq
argument_list|()
decl_stmt|,
name|Fquote
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fuser_variable_p
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fdefun
argument_list|()
decl_stmt|,
name|Flet
argument_list|()
decl_stmt|,
name|FletX
argument_list|()
decl_stmt|,
name|Fwhile
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fcatch
argument_list|()
decl_stmt|,
name|Fthrow
argument_list|()
decl_stmt|,
name|Funwind_protect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fcondition_case
argument_list|()
decl_stmt|,
name|Fsignal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Ffunction_type
argument_list|()
decl_stmt|,
name|Fautoload
argument_list|()
decl_stmt|,
name|Fdocumentation
argument_list|()
decl_stmt|,
name|Fcommandp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Feval
argument_list|()
decl_stmt|,
name|Fapply
argument_list|()
decl_stmt|,
name|Ffuncall
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fglobal_set
argument_list|()
decl_stmt|,
name|Fglobal_value
argument_list|()
decl_stmt|,
name|Fbacktrace
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|call1
argument_list|()
decl_stmt|,
name|call2
argument_list|()
decl_stmt|,
name|call3
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|apply_lambda
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|internal_catch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|internal_condition_case
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unbind_to
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in editfns.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vprefix_arg
decl_stmt|,
name|Qminus
decl_stmt|,
name|Vcurrent_prefix_arg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Finteractive_p
argument_list|()
decl_stmt|,
name|Fgoto_char
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fpoint_min_marker
argument_list|()
decl_stmt|,
name|Fpoint_max_marker
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fpoint_min
argument_list|()
decl_stmt|,
name|Fpoint_max
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fpoint
argument_list|()
decl_stmt|,
name|Fmark
argument_list|()
decl_stmt|,
name|Fpoint_marker
argument_list|()
decl_stmt|,
name|Fmark_marker
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Ffollchar
argument_list|()
decl_stmt|,
name|Fprevchar
argument_list|()
decl_stmt|,
name|Fchar_after
argument_list|()
decl_stmt|,
name|Finsert
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Feolp
argument_list|()
decl_stmt|,
name|Feobp
argument_list|()
decl_stmt|,
name|Fbolp
argument_list|()
decl_stmt|,
name|Fbobp
argument_list|()
decl_stmt|,
name|Fset_mark
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fformat
argument_list|()
decl_stmt|,
name|format1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fgetenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fbuffer_substring
argument_list|()
decl_stmt|,
name|Fbuffer_string
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|save_excursion_save
argument_list|()
decl_stmt|,
name|save_restriction_save
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|save_excursion_restore
argument_list|()
decl_stmt|,
name|save_restriction_restore
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fchar_to_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* defined in buffer.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vbuffer_alist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fget_buffer
argument_list|()
decl_stmt|,
name|Fget_buffer_create
argument_list|()
decl_stmt|,
name|Fset_buffer
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fbarf_if_buffer_read_only
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fcurrent_buffer
argument_list|()
decl_stmt|,
name|Fswitch_to_buffer
argument_list|()
decl_stmt|,
name|Fpop_to_buffer
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fother_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|buffer
modifier|*
name|all_buffers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in marker.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fmarker_position
argument_list|()
decl_stmt|,
name|Fmarker_buffer
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fcopy_marker
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in fileio.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qfile_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fexpand_file_name
argument_list|()
decl_stmt|,
name|Ffile_name_nondirectory
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fsubstitute_in_file_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|Ffile_symlink_p
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in abbrev.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vfundamental_mode_abbrev_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in search.c */
end_comment

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fstring_match
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fscan_buffer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* defined in minibuf.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|last_minibuf_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|read_minibuf_string
argument_list|()
decl_stmt|,
name|Fcompleting_read
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fread_from_minibuffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fread_variable
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fread_minibuffer
argument_list|()
decl_stmt|,
name|Feval_minibuffer
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fread_string
argument_list|()
decl_stmt|,
name|Fread_file_name
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fread_no_blanks_input
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in callint.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vcommand_history
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qcall_interactively
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fcall_interactively
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fprefix_numeric_value
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* defined in casefiddle.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fdowncase
argument_list|()
decl_stmt|,
name|Fupcase
argument_list|()
decl_stmt|,
name|Fcapitalize
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in keyboard.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vhelp_form
decl_stmt|,
name|Vtop_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fdiscard_input
argument_list|()
decl_stmt|,
name|Frecursive_edit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fcommand_execute
argument_list|()
decl_stmt|,
name|Finput_pending_p
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in keymap.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qkeymap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fkey_description
argument_list|()
decl_stmt|,
name|Fsingle_key_description
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fwhere_is_internal
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|access_keymap
argument_list|()
decl_stmt|,
name|store_in_keymap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|get_keyelt
argument_list|()
decl_stmt|,
name|get_keymap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in indent.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fvertical_motion
argument_list|()
decl_stmt|,
name|Findent_to
argument_list|()
decl_stmt|,
name|Fcurrent_column
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in window.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qwindowp
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fget_buffer_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fsave_window_excursion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|save_window_save
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Lisp_Object
name|save_window_restore
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* defined in emacs.c */
end_comment

begin_function_decl
specifier|extern
name|Lisp_Object
name|decode_env_path
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero means don't do interactive redisplay and don't change tty modes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|noninteractive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in process.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fget_process
argument_list|()
decl_stmt|,
name|Fget_buffer_process
argument_list|()
decl_stmt|,
name|Fprocessp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fprocess_status
argument_list|()
decl_stmt|,
name|Fkill_process
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in callproc.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vexec_path
decl_stmt|,
name|Vexec_directory
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in doc.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vdoc_file_name
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fsubstitute_command_keys
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* defined in bytecode.c */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qbytecode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in macros.c */
end_comment

begin_function_decl
specifier|extern
name|Lisp_Object
name|Fexecute_kbd_macro
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debugger
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|,
modifier|*
name|getwd
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

