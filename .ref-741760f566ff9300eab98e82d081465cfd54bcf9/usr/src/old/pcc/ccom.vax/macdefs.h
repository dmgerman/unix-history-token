begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	macdefs.h	4.2	85/08/23	*/
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
value|32
end_define

begin_define
define|#
directive|define
name|AUTOINIT
value|0
end_define

begin_comment
comment|/*  * Storage space requirements  */
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
comment|/*  * Register cookies for stack pointer and argument pointer  */
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

begin_define
define|#
directive|define
name|ARGREG
value|12
end_define

begin_comment
comment|/* off frame pointer */
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
value|11
end_define

begin_comment
comment|/* ... R11 */
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

begin_define
define|#
directive|define
name|FIELDOPS
end_define

begin_comment
comment|/* show field hardware support on VAX */
end_comment

begin_define
define|#
directive|define
name|RTOLBYTES
end_define

begin_comment
comment|/* bytes are numbered from right to left */
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

