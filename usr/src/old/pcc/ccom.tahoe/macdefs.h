begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	macdefs.h	1.2	86/01/23	*/
end_comment

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

begin_comment
comment|/*	size in which constants are converted */
end_comment

begin_comment
comment|/*	should be long if feasable */
end_comment

begin_define
define|#
directive|define
name|CONSZ
value|long
end_define

begin_define
define|#
directive|define
name|ACONFMT
value|"$0x%lx"
end_define

begin_define
define|#
directive|define
name|CONFMT
value|"%ld"
end_define

begin_comment
comment|/*	size in which offsets are kept /*	should be large enough to cover address space in bits */
end_comment

begin_define
define|#
directive|define
name|OFFSZ
value|long
end_define

begin_comment
comment|/* 	character set macro */
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
comment|/* register cookie for stack pointer */
end_comment

begin_define
define|#
directive|define
name|STKREG
value|13
end_define

begin_comment
comment|/*	maximum and minimum register variables */
end_comment

begin_define
define|#
directive|define
name|MAXRVAR
value|12
end_define

begin_define
define|#
directive|define
name|MINRVAR
value|6
end_define

begin_comment
comment|/* various standard pieces of code are used */
end_comment

begin_define
define|#
directive|define
name|STDPRTREE
end_define

begin_define
define|#
directive|define
name|LABFMT
value|"L%d"
end_define

begin_comment
comment|/* show stack grows negatively */
end_comment

begin_define
define|#
directive|define
name|BACKAUTO
end_define

begin_define
define|#
directive|define
name|BACKTEMP
end_define

begin_comment
comment|/* no field hardware support on Tahoe #define FIELDOPS */
end_comment

begin_comment
comment|/* bytes are numbered from left to right #define RTOLBYTES */
end_comment

begin_comment
comment|/* we want prtree included */
end_comment

begin_define
define|#
directive|define
name|STDPRTREE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FORT
end_ifndef

begin_define
define|#
directive|define
name|ONEPASS
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* register char and short are not allowed #define REG_CHAR */
end_comment

begin_comment
comment|/* addr of reg+offset is computed */
end_comment

begin_define
define|#
directive|define
name|ADDROREG
end_define

begin_define
define|#
directive|define
name|FIXDEF
parameter_list|(
name|p
parameter_list|)
value|outstab(p)
end_define

begin_define
define|#
directive|define
name|FIXARG
parameter_list|(
name|p
parameter_list|)
value|fixarg(p)
end_define

begin_define
define|#
directive|define
name|FIXSTRUCT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|outstruct(a,b)
end_define

begin_define
define|#
directive|define
name|PRTDCON
end_define

begin_comment
comment|/* use local version of prtdcon */
end_comment

begin_define
define|#
directive|define
name|ASSTRINGS
end_define

begin_comment
comment|/* assembler recognizes strings */
end_comment

begin_define
define|#
directive|define
name|STABDOT
end_define

begin_comment
comment|/* output .stabdot entries */
end_comment

begin_define
define|#
directive|define
name|LCOMM
end_define

begin_comment
comment|/* .lcomm for non-global commons */
end_comment

begin_define
define|#
directive|define
name|BUFSTDERR
end_define

begin_comment
comment|/* buffer error messages */
end_comment

begin_define
define|#
directive|define
name|FLEXNAMES
end_define

begin_comment
comment|/* unlimited name length */
end_comment

end_unit

