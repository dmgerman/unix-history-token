begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  USEFUL.H -- Some useful stuff. ** **	@(#)useful.h	3.1	%G% */
end_comment

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
endif|NULL
end_endif

begin_define
define|#
directive|define
name|setbit
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|(word |= bit)
end_define

begin_define
define|#
directive|define
name|clrbit
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|(word&= ~bit)
end_define

begin_define
define|#
directive|define
name|bitset
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|((word)& (bit))
end_define

end_unit

