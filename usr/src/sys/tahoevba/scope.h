begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)scope.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOSCOPE
end_ifdef

begin_comment
comment|/*  some i/o addresses used to generate pulses for scopes */
end_comment

begin_define
define|#
directive|define
name|OUT1
value|0xffffb034
end_define

begin_define
define|#
directive|define
name|OUT2
value|0xffffb018
end_define

begin_define
define|#
directive|define
name|OUT3
value|0xffffb020
end_define

begin_define
define|#
directive|define
name|OUT4
value|0xffffb004
end_define

begin_define
define|#
directive|define
name|OUT5
value|0xffffb024
end_define

begin_define
define|#
directive|define
name|OUT6
value|0xffffb00c
end_define

begin_define
define|#
directive|define
name|OUT7
value|0xffffb02c
end_define

begin_define
define|#
directive|define
name|IOaddr
parameter_list|(
name|off
parameter_list|)
value|(caddr_t)(&vmem[(off)& 0x0fffff])
end_define

begin_decl_stmt
specifier|extern
name|char
name|vmem
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cold
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|scope_out
parameter_list|(
name|x
parameter_list|)
value|if (!cold) movob(IOaddr(OUT
comment|/**/
value|x),0)
end_define

begin_define
define|#
directive|define
name|scope_in
parameter_list|(
name|x
parameter_list|)
value|if( !cold) dummy =  *IOaddr(IN
comment|/**/
value|x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|scope_out
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|scope_in
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

