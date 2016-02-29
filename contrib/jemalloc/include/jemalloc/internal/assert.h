begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Define a custom assert() in order to reduce the chances of deadlock during  * assertion failure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|assert
end_ifndef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|e
parameter_list|)
value|do {							\ 	if (unlikely(config_debug&& !(e))) {				\ 		malloc_printf(						\ 		    "<jemalloc>: %s:%d: Failed assertion: \"%s\"\n",	\ 		    __FILE__, __LINE__, #e);				\ 		abort();						\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|not_reached
end_ifndef

begin_define
define|#
directive|define
name|not_reached
parameter_list|()
value|do {						\ 	if (config_debug) {						\ 		malloc_printf(						\ 		    "<jemalloc>: %s:%d: Unreachable code reached\n",	\ 		    __FILE__, __LINE__);				\ 		abort();						\ 	}								\ 	unreachable();							\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|not_implemented
end_ifndef

begin_define
define|#
directive|define
name|not_implemented
parameter_list|()
value|do {						\ 	if (config_debug) {						\ 		malloc_printf("<jemalloc>: %s:%d: Not implemented\n",	\ 		    __FILE__, __LINE__);				\ 		abort();						\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|assert_not_implemented
end_ifndef

begin_define
define|#
directive|define
name|assert_not_implemented
parameter_list|(
name|e
parameter_list|)
value|do {					\ 	if (unlikely(config_debug&& !(e)))				\ 		not_implemented();					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

