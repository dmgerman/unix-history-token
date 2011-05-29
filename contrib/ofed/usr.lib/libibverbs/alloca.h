begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_LIBIBVERBS_ALLOCA_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBIBVERBS_ALLOCA_H_
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|strdupa
parameter_list|(
name|_s
parameter_list|)
define|\
value|({								\ 	char *_d;						\ 	int _len;						\ 								\ 	_len = strlen(_s) + 1;					\ 	_d = alloca(_len);					\ 	if (_d)							\ 		memcpy(_d, _s, _len);				\ 	_d;							\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBIBVERBS_ALLOCA_H_ */
end_comment

end_unit

