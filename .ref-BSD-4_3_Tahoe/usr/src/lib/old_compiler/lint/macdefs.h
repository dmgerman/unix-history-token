begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)macdefs.h	1.5	(Berkeley)	1/8/86	*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|pdp11
argument_list|)
operator|||
name|defined
argument_list|(
name|vax
argument_list|)
end_if

begin_define
define|#
directive|define
name|makecc
parameter_list|(
name|val
parameter_list|,
name|i
parameter_list|)
value|lastcon |= val<<(8*i);
end_define

begin_comment
comment|/* pdp-11 womp next char  */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|makecc
parameter_list|(
name|val
parameter_list|,
name|i
parameter_list|)
value|lastcon = i ? (val<<8)|lastcon : val
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARGINIT
value|288
end_define

begin_comment
comment|/* initial offset for arguments */
end_comment

begin_define
define|#
directive|define
name|AUTOINIT
value|0
end_define

begin_comment
comment|/* initial automatic offset */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|SZCHAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SZINT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SZFLOAT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SZDOUBLE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SZLONG
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SZSHORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SZPOINT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALCHAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALINT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALFLOAT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALDOUBLE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALLONG
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALSHORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALPOINT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ALSTRUCT
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SAVEADJUST
value|0
end_define

begin_comment
comment|/* bits of adjustment required for stackframe */
end_comment

begin_comment
comment|/* type (INT OR LONG) big enough to hold pointers */
end_comment

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
name|CONFMT
value|"%Ld"
end_define

begin_define
define|#
directive|define
name|CONOFMT
value|"%Lo"
end_define

begin_define
define|#
directive|define
name|LABFMT
value|"L%d"
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
comment|/*	register cookie for stack pointer */
end_comment

begin_define
define|#
directive|define
name|STKREG
value|9
end_define

begin_comment
comment|/*	maximum and minimum register variable values */
end_comment

begin_define
define|#
directive|define
name|MAXRVAR
value|1000
end_define

begin_define
define|#
directive|define
name|MINRVAR
value|1
end_define

begin_comment
comment|/* macros carried over from the PCC */
end_comment

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

begin_comment
comment|/* many macro definitions for functions irrelevant to lint */
end_comment

begin_define
define|#
directive|define
name|locctr
parameter_list|(
name|n
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|getlab
parameter_list|()
value|10
end_define

begin_define
define|#
directive|define
name|genswitch
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_define
define|#
directive|define
name|bccode
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cendarg
parameter_list|()
end_define

begin_define
define|#
directive|define
name|incode
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|(inoff += (s))
end_define

begin_define
define|#
directive|define
name|fincode
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|(inoff += (s) )
end_define

begin_define
define|#
directive|define
name|vfdzero
parameter_list|(
name|n
parameter_list|)
value|(inoff += (n))
end_define

begin_define
define|#
directive|define
name|aobeg
parameter_list|()
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
name|econvert
parameter_list|(
name|p
parameter_list|)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|unix
end_ifndef

begin_define
define|#
directive|define
name|NOFORTRAN
value|{extern int pflag; if(pflag) werror( "fortran keyword nonportable" );}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NOFORTRAN
value|{ werror( "fortran keyword nonportable" ); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINT
end_define

end_unit

