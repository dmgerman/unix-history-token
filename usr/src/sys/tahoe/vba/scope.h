begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	scope.h	1.2	86/01/05	*/
end_comment

begin_comment
comment|/*  Some I/O addresses used to generate pulses for scopes */
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
name|int
name|iospace_mapped
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|scope_out
parameter_list|(
name|x
parameter_list|)
value|if(iospace_mapped) movob(IOaddr(OUT
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
value|if(iospace_mapped) dummy =  *IOaddr(IN
comment|/**/
value|x)
end_define

end_unit

