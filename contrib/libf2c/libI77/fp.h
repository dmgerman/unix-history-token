begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|FMAX
value|40
end_define

begin_define
define|#
directive|define
name|EXPMAXDIGS
value|8
end_define

begin_define
define|#
directive|define
name|EXPMAX
value|99999999
end_define

begin_comment
comment|/* FMAX = max number of nonzero digits passed to atof() */
end_comment

begin_comment
comment|/* EXPMAX = 10^EXPMAXDIGS - 1 = largest allowed exponent absolute value */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V10
end_ifdef

begin_comment
comment|/* Research Tenth-Edition Unix */
end_comment

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXFRACDIGS and MAXINTDIGS are for wrt_F -- bounds (not necessarily    tight) on the maximum number of digits to the right and left of  * the decimal point.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_define
define|#
directive|define
name|MAXFRACDIGS
value|56
end_define

begin_define
define|#
directive|define
name|MAXINTDIGS
value|38
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|MAXFRACDIGS
value|9880
end_define

begin_define
define|#
directive|define
name|MAXINTDIGS
value|9864
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* values that suffice for IEEE double */
end_comment

begin_define
define|#
directive|define
name|MAXFRACDIGS
value|344
end_define

begin_define
define|#
directive|define
name|MAXINTDIGS
value|308
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

