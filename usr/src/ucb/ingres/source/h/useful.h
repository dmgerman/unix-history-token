begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  USEFUL.H -- useful stuff. ** **	Version: **		@(#)useful.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/* logical one, true, yes, ok, etc.*/
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/* logical zero, false, no, nop, etc. */
end_comment

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_comment
comment|/* the boolean type */
end_comment

begin_endif
endif|#
directive|endif
endif|TRUE
end_endif

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

begin_comment
comment|/* the null pointer */
end_comment

begin_endif
endif|#
directive|endif
endif|NULL
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bitset
end_ifndef

begin_define
define|#
directive|define
name|bitset
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|((bit)& (word))
end_define

begin_define
define|#
directive|define
name|setbit
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|word |= bit
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
value|word&= ~bit
end_define

begin_endif
endif|#
directive|endif
endif|bitset
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b))? (a): (b))
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
value|(((a)> (b))? (a): (b))
end_define

begin_endif
endif|#
directive|endif
endif|min
end_endif

end_unit

