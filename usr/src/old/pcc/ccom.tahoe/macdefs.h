begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	macdefs.h	1.5	87/12/10	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACDEFS_
end_ifndef

begin_define
define|#
directive|define
name|_MACDEFS_
end_define

begin_define
define|#
directive|define
name|makecc
parameter_list|(
name|val
parameter_list|,
name|i
parameter_list|)
value|lastcon = (lastcon<<8)|((val<<24)>>24);
end_define

begin_define
define|#
directive|define
name|ARGINIT
value|SZINT
end_define

begin_define
define|#
directive|define
name|AUTOINIT
value|(13*SZINT)
end_define

begin_comment
comment|/*  * Storage space requirements.  */
end_comment

begin_define
define|#
directive|define
name|SZCHAR
value|8
end_define

begin_define
define|#
directive|define
name|SZINT
value|32
end_define

begin_define
define|#
directive|define
name|SZFLOAT
value|32
end_define

begin_define
define|#
directive|define
name|SZDOUBLE
value|64
end_define

begin_define
define|#
directive|define
name|SZLONG
value|32
end_define

begin_define
define|#
directive|define
name|SZSHORT
value|16
end_define

begin_define
define|#
directive|define
name|SZPOINT
value|32
end_define

begin_comment
comment|/*  * Alignment constraints  */
end_comment

begin_define
define|#
directive|define
name|ALCHAR
value|8
end_define

begin_define
define|#
directive|define
name|ALINT
value|32
end_define

begin_define
define|#
directive|define
name|ALFLOAT
value|32
end_define

begin_define
define|#
directive|define
name|ALDOUBLE
value|32
end_define

begin_define
define|#
directive|define
name|ALLONG
value|32
end_define

begin_define
define|#
directive|define
name|ALSHORT
value|16
end_define

begin_define
define|#
directive|define
name|ALPOINT
value|32
end_define

begin_define
define|#
directive|define
name|ALSTRUCT
value|8
end_define

begin_define
define|#
directive|define
name|ALSTACK
value|32
end_define

begin_define
define|#
directive|define
name|ACONFMT
value|"$0x%lx"
end_define

begin_comment
comment|/* format for printing address constants */
end_comment

begin_define
define|#
directive|define
name|CONFMT
value|"%ld"
end_define

begin_comment
comment|/* format for printing constants */
end_comment

begin_define
define|#
directive|define
name|LABFMT
value|"L%d"
end_define

begin_comment
comment|/* format for printing labels */
end_comment

begin_typedef
typedef|typedef
name|long
name|CONSZ
typedef|;
end_typedef

begin_comment
comment|/* size in which constants are converted */
end_comment

begin_typedef
typedef|typedef
name|long
name|OFFSZ
typedef|;
end_typedef

begin_comment
comment|/* size in which offsets are kept */
end_comment

begin_define
define|#
directive|define
name|CCTRANS
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|/* character set macro */
end_comment

begin_comment
comment|/*  * Register cookie for stack pointer.  */
end_comment

begin_define
define|#
directive|define
name|STKREG
value|13
end_define

begin_comment
comment|/* stack pointer */
end_comment

begin_comment
comment|/*  * Maximum and minimum register variables  */
end_comment

begin_define
define|#
directive|define
name|MINRVAR
value|6
end_define

begin_comment
comment|/* use R6 thru ... */
end_comment

begin_define
define|#
directive|define
name|MAXRVAR
value|12
end_define

begin_comment
comment|/* ... R12 */
end_comment

begin_define
define|#
directive|define
name|BACKAUTO
end_define

begin_comment
comment|/* stack grows negatively for automatics */
end_comment

begin_define
define|#
directive|define
name|BACKTEMP
end_define

begin_comment
comment|/* stack grows negatively for temporaries */
end_comment

begin_comment
comment|/*#define FIELDOPS	/* no hardware field support */
end_comment

begin_comment
comment|/*#define RTOLBYTES	/* bytes are number from left to right */
end_comment

begin_define
define|#
directive|define
name|ADDROREG
end_define

begin_comment
comment|/* can unwind&o, where o is OREG */
end_comment

begin_define
define|#
directive|define
name|ASSTRINGS
end_define

begin_comment
comment|/* assembler handles string initializations */
end_comment

begin_define
define|#
directive|define
name|STABDOT
end_define

begin_comment
comment|/* assembler understands .stabd */
end_comment

begin_define
define|#
directive|define
name|LCOMM
end_define

begin_comment
comment|/* assembler supports .lcomm */
end_comment

begin_define
define|#
directive|define
name|SPRECC
end_define

begin_comment
comment|/* double only arithmetic not supported */
end_comment

begin_define
define|#
directive|define
name|ENUMSIZE
parameter_list|(
name|high
parameter_list|,
name|low
parameter_list|)
value|INT
end_define

begin_comment
comment|/* enums are always stored in full int */
end_comment

begin_define
define|#
directive|define
name|FIXDEF
parameter_list|(
name|p
parameter_list|)
value|if (!nerrors) outstab(p); else
end_define

begin_define
define|#
directive|define
name|FIXARG
parameter_list|(
name|p
parameter_list|)
value|if (!nerrors) fixarg(p); else
end_define

begin_define
define|#
directive|define
name|FIXSTRUCT
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
value|if (!nerrors) outstruct(p,q); else
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ncopy
end_ifndef

begin_define
define|#
directive|define
name|ncopy
parameter_list|(
name|q
parameter_list|,
name|p
parameter_list|)
value|((q)->in = (p)->in)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|aobeg
parameter_list|()
end_define

begin_define
define|#
directive|define
name|aocode
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|aoend
parameter_list|()
end_define

begin_define
define|#
directive|define
name|deflab
parameter_list|(
name|m
parameter_list|)
value|if (!nerrors) printf("L%d:\n", m); else
end_define

begin_define
define|#
directive|define
name|PRTDCON
end_define

begin_comment
comment|/* use machine-specific prtdcon routine */
end_comment

begin_extern
extern|extern	prtdcon(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

