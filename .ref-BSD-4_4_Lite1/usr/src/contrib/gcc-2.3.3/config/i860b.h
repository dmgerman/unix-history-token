begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"i860.h"
end_include

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i860, BSD)")
end_define

begin_comment
comment|/* BSD UN*X systems use BSD STABS debugging info.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|ASCII_DATA_ASM_OP
value|".byte"
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|,
name|size
parameter_list|)
define|\
value|{ register unsigned i;			\   int inside;				\   inside = FALSE;			\   for (i = 0; i< (size); i++) {	\     if (i % 64 == 0) {			\       if (i != 0) {			\ 	if (inside)			\ 	  putc('"', (f));		\ 	putc('\n', (f));		\ 	inside = FALSE;			\       }					\       fprintf((f), "\t%s ", ASCII_DATA_ASM_OP);	\     }					\     if ((p)[i]< 32 || (p)[i] == '\\' || (p)[i] == '"' || (p)[i]>= 127) {	\       if (inside) {			\ 	putc('"', (f));			\ 	inside = FALSE;			\       }					\       if (i % 64 != 0)			\ 	putc(',', (f));			\       fprintf((f), "%d", (p)[i]);	\     } else {				\       if (!inside) {			\ 	if (i % 64 != 0)		\ 	  putc(',', (f));		\ 	putc('"', (f));			\ 	inside = TRUE;			\       }					\       putc((p)[i], (f));		\     }					\   }					\   if (inside)				\     putc('"', (f));			\   putc('\n', (f));			\ }
end_define

end_unit

