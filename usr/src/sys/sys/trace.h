begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|bit
parameter_list|(
name|a
parameter_list|)
value|(1<<(a))
end_define

begin_define
define|#
directive|define
name|TR_BREAD
value|bit(0)
end_define

begin_define
define|#
directive|define
name|TR_BWRITE
value|bit(1)
end_define

begin_define
define|#
directive|define
name|TR_MISS
value|bit(2)
end_define

begin_define
define|#
directive|define
name|TR_HIT
value|bit(3)
end_define

begin_define
define|#
directive|define
name|TR_RA
value|bit(4)
end_define

begin_define
define|#
directive|define
name|TR_XFOD
value|bit(5)
end_define

begin_define
define|#
directive|define
name|TR_BRELSE
value|bit(6)
end_define

begin_define
define|#
directive|define
name|TR_MALL
value|bit(7)
end_define

begin_define
define|#
directive|define
name|TRCSIZ
value|4096
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|EPAWNJ
argument_list|)
end_if

begin_decl_stmt
name|int
name|tracebuf
index|[
name|TRCSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|tracex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tracewhich
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|trace
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|if (tracewhich&(a)) trace1(a,b,c)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

