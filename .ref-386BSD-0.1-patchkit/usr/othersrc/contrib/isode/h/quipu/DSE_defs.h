begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PEPYPATH
end_ifndef

begin_include
include|#
directive|include
file|<isode/pepsy/DSE_pre_defs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"DSE_pre_defs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|encode_DSE_PSAPaddr
parameter_list|(
name|pe
parameter_list|,
name|top
parameter_list|,
name|len
parameter_list|,
name|buffer
parameter_list|,
name|parm
parameter_list|)
define|\
value|enc_f(_ZPSAPaddrDSE,&_ZDSE_mod, pe, top, len, buffer, (char *) parm)
end_define

begin_define
define|#
directive|define
name|decode_DSE_PSAPaddr
parameter_list|(
name|pe
parameter_list|,
name|top
parameter_list|,
name|len
parameter_list|,
name|buffer
parameter_list|,
name|parm
parameter_list|)
define|\
value|dec_f(_ZPSAPaddrDSE,&_ZDSE_mod, pe, top, len, buffer, (char **) parm)
end_define

begin_define
define|#
directive|define
name|print_DSE_PSAPaddr
parameter_list|(
name|pe
parameter_list|,
name|top
parameter_list|,
name|len
parameter_list|,
name|buffer
parameter_list|,
name|parm
parameter_list|)
define|\
value|prnt_f(_ZPSAPaddrDSE,&_ZDSE_mod, pe, top, len, buffer)
end_define

begin_define
define|#
directive|define
name|print_DSE_PSAPaddr_P
value|_ZPSAPaddrDSE,&_ZDSE_mod
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

end_unit

