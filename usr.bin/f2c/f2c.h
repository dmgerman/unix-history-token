begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* f2c.h  --  Standard Fortran to C header file */
end_comment

begin_comment
comment|/**  barf  [ba:rf]  2.  "He suggested using FORTRAN, and everybody barfed."  	- From The Shogakukan DICTIONARY OF NEW ENGLISH (Second edition) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|F2C_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|F2C_INCLUDE
end_define

begin_typedef
typedef|typedef
name|long
name|int
name|integer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uinteger
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|address
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int
name|shortint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|real
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|doublereal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|real
name|r
decl_stmt|,
name|i
decl_stmt|;
block|}
name|complex
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|doublereal
name|r
decl_stmt|,
name|i
decl_stmt|;
block|}
name|doublecomplex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|logical
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int
name|shortlogical
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|logical1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|integer1
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Adjust for integer*8. */
end_comment

begin_comment
unit|typedef long long longint;
comment|/* system-dependent */
end_comment

begin_comment
unit|typedef unsigned long long ulongint;
comment|/* system-dependent */
end_comment

begin_define
define|#
directive|define
name|qbit_clear
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)& ~((ulongint)1<< (b)))
end_define

begin_define
define|#
directive|define
name|qbit_set
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) |  ((ulongint)1<< (b)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE_
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE_
value|(0)
end_define

begin_comment
comment|/* Extern is for use with -E */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Extern
end_ifndef

begin_define
define|#
directive|define
name|Extern
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I/O stuff */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|f2c_i2
end_ifdef

begin_comment
comment|/* for -i2 */
end_comment

begin_typedef
typedef|typedef
name|short
name|flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ftnlen
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ftnint
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|int
name|flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|ftnlen
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|ftnint
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*external read, write*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|cierr
decl_stmt|;
name|ftnint
name|ciunit
decl_stmt|;
name|flag
name|ciend
decl_stmt|;
name|char
modifier|*
name|cifmt
decl_stmt|;
name|ftnint
name|cirec
decl_stmt|;
block|}
name|cilist
typedef|;
end_typedef

begin_comment
comment|/*internal read, write*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|icierr
decl_stmt|;
name|char
modifier|*
name|iciunit
decl_stmt|;
name|flag
name|iciend
decl_stmt|;
name|char
modifier|*
name|icifmt
decl_stmt|;
name|ftnint
name|icirlen
decl_stmt|;
name|ftnint
name|icirnum
decl_stmt|;
block|}
name|icilist
typedef|;
end_typedef

begin_comment
comment|/*open*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|oerr
decl_stmt|;
name|ftnint
name|ounit
decl_stmt|;
name|char
modifier|*
name|ofnm
decl_stmt|;
name|ftnlen
name|ofnmlen
decl_stmt|;
name|char
modifier|*
name|osta
decl_stmt|;
name|char
modifier|*
name|oacc
decl_stmt|;
name|char
modifier|*
name|ofm
decl_stmt|;
name|ftnint
name|orl
decl_stmt|;
name|char
modifier|*
name|oblnk
decl_stmt|;
block|}
name|olist
typedef|;
end_typedef

begin_comment
comment|/*close*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|cerr
decl_stmt|;
name|ftnint
name|cunit
decl_stmt|;
name|char
modifier|*
name|csta
decl_stmt|;
block|}
name|cllist
typedef|;
end_typedef

begin_comment
comment|/*rewind, backspace, endfile*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|aerr
decl_stmt|;
name|ftnint
name|aunit
decl_stmt|;
block|}
name|alist
typedef|;
end_typedef

begin_comment
comment|/* inquire */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|inerr
decl_stmt|;
name|ftnint
name|inunit
decl_stmt|;
name|char
modifier|*
name|infile
decl_stmt|;
name|ftnlen
name|infilen
decl_stmt|;
name|ftnint
modifier|*
name|inex
decl_stmt|;
comment|/*parameters in standard's order*/
name|ftnint
modifier|*
name|inopen
decl_stmt|;
name|ftnint
modifier|*
name|innum
decl_stmt|;
name|ftnint
modifier|*
name|innamed
decl_stmt|;
name|char
modifier|*
name|inname
decl_stmt|;
name|ftnlen
name|innamlen
decl_stmt|;
name|char
modifier|*
name|inacc
decl_stmt|;
name|ftnlen
name|inacclen
decl_stmt|;
name|char
modifier|*
name|inseq
decl_stmt|;
name|ftnlen
name|inseqlen
decl_stmt|;
name|char
modifier|*
name|indir
decl_stmt|;
name|ftnlen
name|indirlen
decl_stmt|;
name|char
modifier|*
name|infmt
decl_stmt|;
name|ftnlen
name|infmtlen
decl_stmt|;
name|char
modifier|*
name|inform
decl_stmt|;
name|ftnint
name|informlen
decl_stmt|;
name|char
modifier|*
name|inunf
decl_stmt|;
name|ftnlen
name|inunflen
decl_stmt|;
name|ftnint
modifier|*
name|inrecl
decl_stmt|;
name|ftnint
modifier|*
name|innrec
decl_stmt|;
name|char
modifier|*
name|inblank
decl_stmt|;
name|ftnlen
name|inblanklen
decl_stmt|;
block|}
name|inlist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_union
union|union
name|Multitype
block|{
comment|/* for multiple entry points */
name|integer1
name|g
decl_stmt|;
name|shortint
name|h
decl_stmt|;
name|integer
name|i
decl_stmt|;
comment|/* longint j; */
name|real
name|r
decl_stmt|;
name|doublereal
name|d
decl_stmt|;
name|complex
name|c
decl_stmt|;
name|doublecomplex
name|z
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|Multitype
name|Multitype
typedef|;
end_typedef

begin_comment
comment|/*typedef long int Long;*/
end_comment

begin_comment
comment|/* No longer used; formerly in Namelist */
end_comment

begin_struct
struct|struct
name|Vardesc
block|{
comment|/* for Namelist */
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|addr
decl_stmt|;
name|ftnlen
modifier|*
name|dims
decl_stmt|;
name|int
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Vardesc
name|Vardesc
typedef|;
end_typedef

begin_struct
struct|struct
name|Namelist
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|Vardesc
modifier|*
modifier|*
name|vars
decl_stmt|;
name|int
name|nvars
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Namelist
name|Namelist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|((x)>= 0 ? (x) : -(x))
end_define

begin_define
define|#
directive|define
name|dabs
parameter_list|(
name|x
parameter_list|)
value|(doublereal)abs(x)
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<= (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>= (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|dmin
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(doublereal)min(a,b)
end_define

begin_define
define|#
directive|define
name|dmax
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(doublereal)max(a,b)
end_define

begin_define
define|#
directive|define
name|bit_test
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>> (b)& 1)
end_define

begin_define
define|#
directive|define
name|bit_clear
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)& ~((uinteger)1<< (b)))
end_define

begin_define
define|#
directive|define
name|bit_set
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) |  ((uinteger)1<< (b)))
end_define

begin_comment
comment|/* procedure parameter types for -A and -C++ */
end_comment

begin_define
define|#
directive|define
name|F2C_proc_par_types
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_typedef
typedef|typedef
name|int
comment|/* Unknown procedure type */
function_decl|(
modifier|*
name|U_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|shortint
function_decl|(
modifier|*
name|J_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|integer
function_decl|(
modifier|*
name|I_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|real
function_decl|(
modifier|*
name|R_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|doublereal
argument_list|(
operator|*
name|D_fp
argument_list|)
argument_list|(
operator|...
argument_list|)
typedef|,
argument_list|(
operator|*
name|E_fp
argument_list|)
argument_list|(
operator|...
argument_list|)
typedef|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Complex */
name|VOID
function_decl|(
modifier|*
name|C_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Double Complex */
name|VOID
function_decl|(
modifier|*
name|Z_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|logical
function_decl|(
modifier|*
name|L_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|shortlogical
function_decl|(
modifier|*
name|K_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Character */
name|VOID
function_decl|(
modifier|*
name|H_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Subroutine */
name|int
function_decl|(
modifier|*
name|S_fp
function_decl|)
parameter_list|(
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
comment|/* Unknown procedure type */
function_decl|(
modifier|*
name|U_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|shortint
function_decl|(
modifier|*
name|J_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|integer
function_decl|(
modifier|*
name|I_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|real
function_decl|(
modifier|*
name|R_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|doublereal
argument_list|(
operator|*
name|D_fp
argument_list|)
argument_list|()
typedef|,
argument_list|(
operator|*
name|E_fp
argument_list|)
argument_list|()
typedef|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Complex */
name|VOID
function_decl|(
modifier|*
name|C_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Double Complex */
name|VOID
function_decl|(
modifier|*
name|Z_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|logical
function_decl|(
modifier|*
name|L_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|shortlogical
function_decl|(
modifier|*
name|K_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Character */
name|VOID
function_decl|(
modifier|*
name|H_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
comment|/* Subroutine */
name|int
function_decl|(
modifier|*
name|S_fp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* E_fp is for real functions when -R is not specified */
end_comment

begin_typedef
typedef|typedef
name|VOID
name|C_f
typedef|;
end_typedef

begin_comment
comment|/* complex function */
end_comment

begin_typedef
typedef|typedef
name|VOID
name|H_f
typedef|;
end_typedef

begin_comment
comment|/* character function */
end_comment

begin_typedef
typedef|typedef
name|VOID
name|Z_f
typedef|;
end_typedef

begin_comment
comment|/* double complex function */
end_comment

begin_typedef
typedef|typedef
name|doublereal
name|E_f
typedef|;
end_typedef

begin_comment
comment|/* real function with -R not specified */
end_comment

begin_comment
comment|/* undef any lower-case symbols that your C compiler predefines, e.g.: */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Skip_f2c_Undefs
end_ifndef

begin_undef
undef|#
directive|undef
name|cray
end_undef

begin_undef
undef|#
directive|undef
name|gcos
end_undef

begin_undef
undef|#
directive|undef
name|mc68010
end_undef

begin_undef
undef|#
directive|undef
name|mc68020
end_undef

begin_undef
undef|#
directive|undef
name|mips
end_undef

begin_undef
undef|#
directive|undef
name|pdp11
end_undef

begin_undef
undef|#
directive|undef
name|sgi
end_undef

begin_undef
undef|#
directive|undef
name|sparc
end_undef

begin_undef
undef|#
directive|undef
name|sun
end_undef

begin_undef
undef|#
directive|undef
name|sun2
end_undef

begin_undef
undef|#
directive|undef
name|sun3
end_undef

begin_undef
undef|#
directive|undef
name|sun4
end_undef

begin_undef
undef|#
directive|undef
name|u370
end_undef

begin_undef
undef|#
directive|undef
name|u3b
end_undef

begin_undef
undef|#
directive|undef
name|u3b2
end_undef

begin_undef
undef|#
directive|undef
name|u3b5
end_undef

begin_undef
undef|#
directive|undef
name|unix
end_undef

begin_undef
undef|#
directive|undef
name|vax
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

