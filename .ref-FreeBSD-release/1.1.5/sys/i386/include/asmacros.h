begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|ALIGN_DATA
value|.align	2
end_define

begin_comment
comment|/* 4 byte alignment, zero filled */
end_comment

begin_define
define|#
directive|define
name|ALIGN_TEXT
value|.align	2,0x90
end_define

begin_comment
comment|/* 4-byte alignment, nop filled */
end_comment

begin_define
define|#
directive|define
name|SUPERALIGN_TEXT
value|.align	4,0x90
end_define

begin_comment
comment|/* 16-byte alignment (better for 486), nop filled */
end_comment

begin_define
define|#
directive|define
name|GEN_ENTRY
parameter_list|(
name|name
parameter_list|)
value|ALIGN_TEXT;	.globl name; name:
end_define

begin_define
define|#
directive|define
name|NON_GPROF_ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name)
end_define

begin_comment
comment|/* These three are place holders for future changes to the profiling code */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_LABEL
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MEXITCOUNT
end_define

begin_define
define|#
directive|define
name|FAKE_MCOUNT
parameter_list|(
name|caller
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_comment
comment|/*  * ALTENTRY() must be before a corresponding ENTRY() so that it can jump  * over the mcounting.  */
end_comment

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name); MCOUNT; jmp 2f
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name); MCOUNT; 2:
end_define

begin_comment
comment|/*  * The call to mcount supports the usual (bad) conventions.  We allocate  * some data and pass a pointer to it although the FreeBSD doesn't use  * the data.  We set up a frame before calling mcount because that is  * the standard convention although it makes work for both mcount and  * callers.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT
value|.data; ALIGN_DATA; 1:; .long 0; .text; \ 			pushl %ebp; movl %esp,%ebp; \ 			movl $1b,%eax; call mcount; popl %ebp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * ALTENTRY() has to align because it is before a corresponding ENTRY().  * ENTRY() has to align to because there may be no ALTENTRY() before it.  * If there is a previous ALTENTRY() then the alignment code is empty.  */
end_comment

begin_define
define|#
directive|define
name|ALTENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name)
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|)
value|GEN_ENTRY(_
comment|/**/
value|name)
end_define

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DUMMY_NOPS
end_ifdef

begin_comment
comment|/* this will break some older machines */
end_comment

begin_define
define|#
directive|define
name|FASTER_NOP
end_define

begin_define
define|#
directive|define
name|NOP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FASTER_NOP
value|pushl %eax ; inb $0x84,%al ; popl %eax
end_define

begin_define
define|#
directive|define
name|NOP
value|pushl %eax ; inb $0x84,%al ; inb $0x84,%al ; popl %eax
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

