begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generated automatically by the program `genattr' from the machine description file `md'.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
condition|?
name|USE_PROTOTYPES
expr|:
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_ATTR_alternative
end_define

begin_define
define|#
directive|define
name|get_attr_alternative
parameter_list|(
name|insn
parameter_list|)
value|which_alternative
end_define

begin_define
define|#
directive|define
name|ATTR_FLAG_forward
value|0x1
end_define

begin_define
define|#
directive|define
name|ATTR_FLAG_backward
value|0x2
end_define

begin_define
define|#
directive|define
name|ATTR_FLAG_likely
value|0x4
end_define

begin_define
define|#
directive|define
name|ATTR_FLAG_very_likely
value|0x8
end_define

begin_define
define|#
directive|define
name|ATTR_FLAG_unlikely
value|0x10
end_define

begin_define
define|#
directive|define
name|ATTR_FLAG_very_unlikely
value|0x20
end_define

end_unit

