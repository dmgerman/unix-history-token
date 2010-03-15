begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inffas86.c is a hand tuned assembler version of  *  * inffast.c -- fast decoding  * Copyright (C) 1995-2003 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  *  * Copyright (C) 2003 Chris Anderson<christop@charm.net>  * Please use the copyright conditions above.  *  * Dec-29-2003 -- I added AMD64 inflate asm support.  This version is also  * slightly quicker on x86 systems because, instead of using rep movsb to copy  * data, it uses rep movsw, which moves data in 2-byte chunks instead of single  * bytes.  I've tested the AMD64 code on a Fedora Core 1 + the x86_64 updates  * from http://fedora.linux.duke.edu/fc1_x86_64  * which is running on an Athlon 64 3000+ / Gigabyte GA-K8VT800M system with  * 1GB ram.  The 64-bit version is about 4% faster than the 32-bit version,  * when decompressing mozilla-source-1.3.tar.gz.  *  * Mar-13-2003 -- Most of this is derived from inffast.S which is derived from  * the gcc -S output of zlib-1.2.0/inffast.c.  Zlib-1.2.0 is in beta release at  * the moment.  I have successfully compiled and tested this code with gcc2.96,  * gcc3.2, icc5.0, msvc6.0.  It is very close to the speed of inffast.S  * compiled with gcc -DNO_MMX, but inffast.S is still faster on the P3 with MMX  * enabled.  I will attempt to merge the MMX code into this version.  Newer  * versions of this and inffast.S can be found at  * http://www.eetbeetee.com/zlib/ and http://www.charm.net/~christop/zlib/  */
end_comment

begin_include
include|#
directive|include
file|"zutil.h"
end_include

begin_include
include|#
directive|include
file|"inftrees.h"
end_include

begin_include
include|#
directive|include
file|"inflate.h"
end_include

begin_include
include|#
directive|include
file|"inffast.h"
end_include

begin_comment
comment|/* Mark Adler's comments from inffast.c: */
end_comment

begin_comment
comment|/*    Decode literal, length, and distance codes and write out the resulting    literal and match bytes until either not enough input or output is    available, an end-of-block is encountered, or a data error is encountered.    When large enough input and output buffers are supplied to inflate(), for    example, a 16K input buffer and a 64K output buffer, more than 95% of the    inflate execution time is spent in this routine.     Entry assumptions:          state->mode == LEN         strm->avail_in>= 6         strm->avail_out>= 258         start>= strm->avail_out         state->bits< 8     On return, state->mode is one of:          LEN -- ran out of enough output space or enough available input         TYPE -- reached end of block code, inflate() to interpret next block         BAD -- error in block data     Notes:      - The maximum input bits used by a length/distance pair is 15 bits for the       length code, 5 bits for the length extra, 15 bits for the distance code,       and 13 bits for the distance extra.  This totals 48 bits, or six bytes.       Therefore if strm->avail_in>= 6, then there is enough input to avoid       checking for available input while decoding.      - The maximum bytes that a single length/distance pair can output is 258       bytes, which is the maximum length that can be coded.  inflate_fast()       requires strm->avail_out>= 258 for each loop to avoid checking for       output space.  */
end_comment

begin_function
name|void
name|inflate_fast
parameter_list|(
name|strm
parameter_list|,
name|start
parameter_list|)
name|z_streamp
name|strm
decl_stmt|;
name|unsigned
name|start
decl_stmt|;
comment|/* inflate()'s starting value for strm->avail_out */
block|{
name|struct
name|inflate_state
name|FAR
modifier|*
name|state
decl_stmt|;
struct|struct
name|inffast_ar
block|{
comment|/* 64   32                               x86  x86_64 */
comment|/* ar offset                              register */
comment|/*  0    0 */
name|void
modifier|*
name|esp
decl_stmt|;
comment|/* esp save */
comment|/*  8    4 */
name|void
modifier|*
name|ebp
decl_stmt|;
comment|/* ebp save */
comment|/* 16    8 */
name|unsigned
name|char
name|FAR
modifier|*
name|in
decl_stmt|;
comment|/* esi rsi  local strm->next_in */
comment|/* 24   12 */
name|unsigned
name|char
name|FAR
modifier|*
name|last
decl_stmt|;
comment|/*     r9   while in< last */
comment|/* 32   16 */
name|unsigned
name|char
name|FAR
modifier|*
name|out
decl_stmt|;
comment|/* edi rdi  local strm->next_out */
comment|/* 40   20 */
name|unsigned
name|char
name|FAR
modifier|*
name|beg
decl_stmt|;
comment|/*          inflate()'s init next_out */
comment|/* 48   24 */
name|unsigned
name|char
name|FAR
modifier|*
name|end
decl_stmt|;
comment|/*     r10  while out< end */
comment|/* 56   28 */
name|unsigned
name|char
name|FAR
modifier|*
name|window
decl_stmt|;
comment|/*          size of window, wsize!=0 */
comment|/* 64   32 */
name|code
specifier|const
name|FAR
modifier|*
name|lcode
decl_stmt|;
comment|/* ebp rbp  local strm->lencode */
comment|/* 72   36 */
name|code
specifier|const
name|FAR
modifier|*
name|dcode
decl_stmt|;
comment|/*     r11  local strm->distcode */
comment|/* 80   40 */
name|unsigned
name|long
name|hold
decl_stmt|;
comment|/* edx rdx  local strm->hold */
comment|/* 88   44 */
name|unsigned
name|bits
decl_stmt|;
comment|/* ebx rbx  local strm->bits */
comment|/* 92   48 */
name|unsigned
name|wsize
decl_stmt|;
comment|/*          window size */
comment|/* 96   52 */
name|unsigned
name|write
decl_stmt|;
comment|/*          window write index */
comment|/*100   56 */
name|unsigned
name|lmask
decl_stmt|;
comment|/*     r12  mask for lcode */
comment|/*104   60 */
name|unsigned
name|dmask
decl_stmt|;
comment|/*     r13  mask for dcode */
comment|/*108   64 */
name|unsigned
name|len
decl_stmt|;
comment|/*     r14  match length */
comment|/*112   68 */
name|unsigned
name|dist
decl_stmt|;
comment|/*     r15  match distance */
comment|/*116   72 */
name|unsigned
name|status
decl_stmt|;
comment|/*          set when state chng*/
block|}
name|ar
struct|;
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__i386
argument_list|)
define|#
directive|define
name|PAD_AVAIL_IN
value|6
define|#
directive|define
name|PAD_AVAIL_OUT
value|258
else|#
directive|else
define|#
directive|define
name|PAD_AVAIL_IN
value|5
define|#
directive|define
name|PAD_AVAIL_OUT
value|257
endif|#
directive|endif
comment|/* copy state to local variables */
name|state
operator|=
operator|(
expr|struct
name|inflate_state
name|FAR
operator|*
operator|)
name|strm
operator|->
name|state
expr_stmt|;
name|ar
operator|.
name|in
operator|=
name|strm
operator|->
name|next_in
expr_stmt|;
name|ar
operator|.
name|last
operator|=
name|ar
operator|.
name|in
operator|+
operator|(
name|strm
operator|->
name|avail_in
operator|-
name|PAD_AVAIL_IN
operator|)
expr_stmt|;
name|ar
operator|.
name|out
operator|=
name|strm
operator|->
name|next_out
expr_stmt|;
name|ar
operator|.
name|beg
operator|=
name|ar
operator|.
name|out
operator|-
operator|(
name|start
operator|-
name|strm
operator|->
name|avail_out
operator|)
expr_stmt|;
name|ar
operator|.
name|end
operator|=
name|ar
operator|.
name|out
operator|+
operator|(
name|strm
operator|->
name|avail_out
operator|-
name|PAD_AVAIL_OUT
operator|)
expr_stmt|;
name|ar
operator|.
name|wsize
operator|=
name|state
operator|->
name|wsize
expr_stmt|;
name|ar
operator|.
name|write
operator|=
name|state
operator|->
name|wnext
expr_stmt|;
name|ar
operator|.
name|window
operator|=
name|state
operator|->
name|window
expr_stmt|;
name|ar
operator|.
name|hold
operator|=
name|state
operator|->
name|hold
expr_stmt|;
name|ar
operator|.
name|bits
operator|=
name|state
operator|->
name|bits
expr_stmt|;
name|ar
operator|.
name|lcode
operator|=
name|state
operator|->
name|lencode
expr_stmt|;
name|ar
operator|.
name|dcode
operator|=
name|state
operator|->
name|distcode
expr_stmt|;
name|ar
operator|.
name|lmask
operator|=
operator|(
literal|1U
operator|<<
name|state
operator|->
name|lenbits
operator|)
operator|-
literal|1
expr_stmt|;
name|ar
operator|.
name|dmask
operator|=
operator|(
literal|1U
operator|<<
name|state
operator|->
name|distbits
operator|)
operator|-
literal|1
expr_stmt|;
comment|/* decode literals and length/distances until end-of-block or not enough        input data or output space */
comment|/* align in on 1/2 hold size boundary */
while|while
condition|(
operator|(
operator|(
name|unsigned
name|long
operator|)
operator|(
name|void
operator|*
operator|)
name|ar
operator|.
name|in
operator|&
operator|(
sizeof|sizeof
argument_list|(
name|ar
operator|.
name|hold
argument_list|)
operator|/
literal|2
operator|-
literal|1
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|ar
operator|.
name|hold
operator|+=
operator|(
name|unsigned
name|long
operator|)
operator|*
name|ar
operator|.
name|in
operator|++
operator|<<
name|ar
operator|.
name|bits
expr_stmt|;
name|ar
operator|.
name|bits
operator|+=
literal|8
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__i386
argument_list|)
asm|__asm__
specifier|__volatile__
asm|( "        leaq    %0, %%rax\n" "        movq    %%rbp, 8(%%rax)\n"
comment|/* save regs rbp and rsp */
asm|"        movq    %%rsp, (%%rax)\n" "        movq    %%rax, %%rsp\n"
comment|/* make rsp point to&ar */
asm|"        movq    16(%%rsp), %%rsi\n"
comment|/* rsi  = in */
asm|"        movq    32(%%rsp), %%rdi\n"
comment|/* rdi  = out */
asm|"        movq    24(%%rsp), %%r9\n"
comment|/* r9   = last */
asm|"        movq    48(%%rsp), %%r10\n"
comment|/* r10  = end */
asm|"        movq    64(%%rsp), %%rbp\n"
comment|/* rbp  = lcode */
asm|"        movq    72(%%rsp), %%r11\n"
comment|/* r11  = dcode */
asm|"        movq    80(%%rsp), %%rdx\n"
comment|/* rdx  = hold */
asm|"        movl    88(%%rsp), %%ebx\n"
comment|/* ebx  = bits */
asm|"        movl    100(%%rsp), %%r12d\n"
comment|/* r12d = lmask */
asm|"        movl    104(%%rsp), %%r13d\n"
comment|/* r13d = dmask */
comment|/* r14d = len */
comment|/* r15d = dist */
asm|"        cld\n" "        cmpq    %%rdi, %%r10\n" "        je      .L_one_time\n"
comment|/* if only one decode left */
asm|"        cmpq    %%rsi, %%r9\n" "        je      .L_one_time\n" "        jmp     .L_do_loop\n"  ".L_one_time:\n" "        movq    %%r12, %%r8\n"
comment|/* r8 = lmask */
asm|"        cmpb    $32, %%bl\n" "        ja      .L_get_length_code_one_time\n"  "        lodsl\n"
comment|/* eax = *(uint *)in++ */
asm|"        movb    %%bl, %%cl\n"
comment|/* cl = bits, needs it for shifting */
asm|"        addb    $32, %%bl\n"
comment|/* bits += 32 */
asm|"        shlq    %%cl, %%rax\n" "        orq     %%rax, %%rdx\n"
comment|/* hold |= *((uint *)in)++<< bits */
asm|"        jmp     .L_get_length_code_one_time\n"  ".align 32,0x90\n" ".L_while_test:\n" "        cmpq    %%rdi, %%r10\n" "        jbe     .L_break_loop\n" "        cmpq    %%rsi, %%r9\n" "        jbe     .L_break_loop\n"  ".L_do_loop:\n" "        movq    %%r12, %%r8\n"
comment|/* r8 = lmask */
asm|"        cmpb    $32, %%bl\n" "        ja      .L_get_length_code\n"
comment|/* if (32< bits) */
asm|"        lodsl\n"
comment|/* eax = *(uint *)in++ */
asm|"        movb    %%bl, %%cl\n"
comment|/* cl = bits, needs it for shifting */
asm|"        addb    $32, %%bl\n"
comment|/* bits += 32 */
asm|"        shlq    %%cl, %%rax\n" "        orq     %%rax, %%rdx\n"
comment|/* hold |= *((uint *)in)++<< bits */
asm|".L_get_length_code:\n" "        andq    %%rdx, %%r8\n"
comment|/* r8&= hold */
asm|"        movl    (%%rbp,%%r8,4), %%eax\n"
comment|/* eax = lcode[hold& lmask] */
asm|"        movb    %%ah, %%cl\n"
comment|/* cl = this.bits */
asm|"        subb    %%ah, %%bl\n"
comment|/* bits -= this.bits */
asm|"        shrq    %%cl, %%rdx\n"
comment|/* hold>>= this.bits */
asm|"        testb   %%al, %%al\n" "        jnz     .L_test_for_length_base\n"
comment|/* if (op != 0) 45.7% */
asm|"        movq    %%r12, %%r8\n"
comment|/* r8 = lmask */
asm|"        shrl    $16, %%eax\n"
comment|/* output this.val char */
asm|"        stosb\n"  ".L_get_length_code_one_time:\n" "        andq    %%rdx, %%r8\n"
comment|/* r8&= hold */
asm|"        movl    (%%rbp,%%r8,4), %%eax\n"
comment|/* eax = lcode[hold& lmask] */
asm|".L_dolen:\n" "        movb    %%ah, %%cl\n"
comment|/* cl = this.bits */
asm|"        subb    %%ah, %%bl\n"
comment|/* bits -= this.bits */
asm|"        shrq    %%cl, %%rdx\n"
comment|/* hold>>= this.bits */
asm|"        testb   %%al, %%al\n" "        jnz     .L_test_for_length_base\n"
comment|/* if (op != 0) 45.7% */
asm|"        shrl    $16, %%eax\n"
comment|/* output this.val char */
asm|"        stosb\n" "        jmp     .L_while_test\n"  ".align 32,0x90\n" ".L_test_for_length_base:\n" "        movl    %%eax, %%r14d\n"
comment|/* len = this */
asm|"        shrl    $16, %%r14d\n"
comment|/* len = this.val */
asm|"        movb    %%al, %%cl\n"  "        testb   $16, %%al\n" "        jz      .L_test_for_second_level_length\n"
comment|/* if ((op& 16) == 0) 8% */
asm|"        andb    $15, %%cl\n"
comment|/* op&= 15 */
asm|"        jz      .L_decode_distance\n"
comment|/* if (!op) */
asm|".L_add_bits_to_len:\n" "        subb    %%cl, %%bl\n" "        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n" "        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        shrq    %%cl, %%rdx\n" "        addl    %%eax, %%r14d\n"
comment|/* len += hold& mask[op] */
asm|".L_decode_distance:\n" "        movq    %%r13, %%r8\n"
comment|/* r8 = dmask */
asm|"        cmpb    $32, %%bl\n" "        ja      .L_get_distance_code\n"
comment|/* if (32< bits) */
asm|"        lodsl\n"
comment|/* eax = *(uint *)in++ */
asm|"        movb    %%bl, %%cl\n"
comment|/* cl = bits, needs it for shifting */
asm|"        addb    $32, %%bl\n"
comment|/* bits += 32 */
asm|"        shlq    %%cl, %%rax\n" "        orq     %%rax, %%rdx\n"
comment|/* hold |= *((uint *)in)++<< bits */
asm|".L_get_distance_code:\n" "        andq    %%rdx, %%r8\n"
comment|/* r8&= hold */
asm|"        movl    (%%r11,%%r8,4), %%eax\n"
comment|/* eax = dcode[hold& dmask] */
asm|".L_dodist:\n" "        movl    %%eax, %%r15d\n"
comment|/* dist = this */
asm|"        shrl    $16, %%r15d\n"
comment|/* dist = this.val */
asm|"        movb    %%ah, %%cl\n" "        subb    %%ah, %%bl\n"
comment|/* bits -= this.bits */
asm|"        shrq    %%cl, %%rdx\n"
comment|/* hold>>= this.bits */
asm|"        movb    %%al, %%cl\n"
comment|/* cl = this.op */
asm|"        testb   $16, %%al\n"
comment|/* if ((op& 16) == 0) */
asm|"        jz      .L_test_for_second_level_dist\n" "        andb    $15, %%cl\n"
comment|/* op&= 15 */
asm|"        jz      .L_check_dist_one\n"  ".L_add_bits_to_dist:\n" "        subb    %%cl, %%bl\n" "        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n"
comment|/* (1<< op) - 1 */
asm|"        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        shrq    %%cl, %%rdx\n" "        addl    %%eax, %%r15d\n"
comment|/* dist += hold& ((1<< op) - 1) */
asm|".L_check_window:\n" "        movq    %%rsi, %%r8\n"
comment|/* save in so from can use it's reg */
asm|"        movq    %%rdi, %%rax\n" "        subq    40(%%rsp), %%rax\n"
comment|/* nbytes = out - beg */
asm|"        cmpl    %%r15d, %%eax\n" "        jb      .L_clip_window\n"
comment|/* if (dist> nbytes) 4.2% */
asm|"        movl    %%r14d, %%ecx\n"
comment|/* ecx = len */
asm|"        movq    %%rdi, %%rsi\n" "        subq    %%r15, %%rsi\n"
comment|/* from = out - dist */
asm|"        sarl    %%ecx\n" "        jnc     .L_copy_two\n"
comment|/* if len % 2 == 0 */
asm|"        rep     movsw\n" "        movb    (%%rsi), %%al\n" "        movb    %%al, (%%rdi)\n" "        incq    %%rdi\n"  "        movq    %%r8, %%rsi\n"
comment|/* move in back to %rsi, toss from */
asm|"        jmp     .L_while_test\n"  ".L_copy_two:\n" "        rep     movsw\n" "        movq    %%r8, %%rsi\n"
comment|/* move in back to %rsi, toss from */
asm|"        jmp     .L_while_test\n"  ".align 32,0x90\n" ".L_check_dist_one:\n" "        cmpl    $1, %%r15d\n"
comment|/* if dist 1, is a memset */
asm|"        jne     .L_check_window\n" "        cmpq    %%rdi, 40(%%rsp)\n"
comment|/* if out == beg, outside window */
asm|"        je      .L_check_window\n"  "        movl    %%r14d, %%ecx\n"
comment|/* ecx = len */
asm|"        movb    -1(%%rdi), %%al\n" "        movb    %%al, %%ah\n"  "        sarl    %%ecx\n" "        jnc     .L_set_two\n" "        movb    %%al, (%%rdi)\n" "        incq    %%rdi\n"  ".L_set_two:\n" "        rep     stosw\n" "        jmp     .L_while_test\n"  ".align 32,0x90\n" ".L_test_for_second_level_length:\n" "        testb   $64, %%al\n" "        jnz     .L_test_for_end_of_block\n"
comment|/* if ((op& 64) != 0) */
asm|"        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n" "        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        addl    %%r14d, %%eax\n"
comment|/* eax += len */
asm|"        movl    (%%rbp,%%rax,4), %%eax\n"
comment|/* eax = lcode[val+(hold&mask[op])]*/
asm|"        jmp     .L_dolen\n"  ".align 32,0x90\n" ".L_test_for_second_level_dist:\n" "        testb   $64, %%al\n" "        jnz     .L_invalid_distance_code\n"
comment|/* if ((op& 64) != 0) */
asm|"        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n" "        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        addl    %%r15d, %%eax\n"
comment|/* eax += dist */
asm|"        movl    (%%r11,%%rax,4), %%eax\n"
comment|/* eax = dcode[val+(hold&mask[op])]*/
asm|"        jmp     .L_dodist\n"  ".align 32,0x90\n" ".L_clip_window:\n" "        movl    %%eax, %%ecx\n"
comment|/* ecx = nbytes */
asm|"        movl    92(%%rsp), %%eax\n"
comment|/* eax = wsize, prepare for dist cmp */
asm|"        negl    %%ecx\n"
comment|/* nbytes = -nbytes */
asm|"        cmpl    %%r15d, %%eax\n" "        jb      .L_invalid_distance_too_far\n"
comment|/* if (dist> wsize) */
asm|"        addl    %%r15d, %%ecx\n"
comment|/* nbytes = dist - nbytes */
asm|"        cmpl    $0, 96(%%rsp)\n" "        jne     .L_wrap_around_window\n"
comment|/* if (write != 0) */
asm|"        movq    56(%%rsp), %%rsi\n"
comment|/* from  = window */
asm|"        subl    %%ecx, %%eax\n"
comment|/* eax  -= nbytes */
asm|"        addq    %%rax, %%rsi\n"
comment|/* from += wsize - nbytes */
asm|"        movl    %%r14d, %%eax\n"
comment|/* eax = len */
asm|"        cmpl    %%ecx, %%r14d\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* eax -= nbytes */
asm|"        rep     movsb\n" "        movq    %%rdi, %%rsi\n" "        subq    %%r15, %%rsi\n"
comment|/* from =&out[ -dist ] */
asm|"        jmp     .L_do_copy\n"  ".align 32,0x90\n" ".L_wrap_around_window:\n" "        movl    96(%%rsp), %%eax\n"
comment|/* eax = write */
asm|"        cmpl    %%eax, %%ecx\n" "        jbe     .L_contiguous_in_window\n"
comment|/* if (write>= nbytes) */
asm|"        movl    92(%%rsp), %%esi\n"
comment|/* from  = wsize */
asm|"        addq    56(%%rsp), %%rsi\n"
comment|/* from += window */
asm|"        addq    %%rax, %%rsi\n"
comment|/* from += write */
asm|"        subq    %%rcx, %%rsi\n"
comment|/* from -= nbytes */
asm|"        subl    %%eax, %%ecx\n"
comment|/* nbytes -= write */
asm|"        movl    %%r14d, %%eax\n"
comment|/* eax = len */
asm|"        cmpl    %%ecx, %%eax\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* len -= nbytes */
asm|"        rep     movsb\n" "        movq    56(%%rsp), %%rsi\n"
comment|/* from = window */
asm|"        movl    96(%%rsp), %%ecx\n"
comment|/* nbytes = write */
asm|"        cmpl    %%ecx, %%eax\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* len -= nbytes */
asm|"        rep     movsb\n" "        movq    %%rdi, %%rsi\n" "        subq    %%r15, %%rsi\n"
comment|/* from = out - dist */
asm|"        jmp     .L_do_copy\n"  ".align 32,0x90\n" ".L_contiguous_in_window:\n" "        movq    56(%%rsp), %%rsi\n"
comment|/* rsi = window */
asm|"        addq    %%rax, %%rsi\n" "        subq    %%rcx, %%rsi\n"
comment|/* from += write - nbytes */
asm|"        movl    %%r14d, %%eax\n"
comment|/* eax = len */
asm|"        cmpl    %%ecx, %%eax\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* len -= nbytes */
asm|"        rep     movsb\n" "        movq    %%rdi, %%rsi\n" "        subq    %%r15, %%rsi\n"
comment|/* from = out - dist */
asm|"        jmp     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|".align 32,0x90\n" ".L_do_copy:\n" "        movl    %%eax, %%ecx\n"
comment|/* ecx = len */
asm|"        rep     movsb\n"  "        movq    %%r8, %%rsi\n"
comment|/* move in back to %esi, toss from */
asm|"        jmp     .L_while_test\n"  ".L_test_for_end_of_block:\n" "        testb   $32, %%al\n" "        jz      .L_invalid_literal_length_code\n" "        movl    $1, 116(%%rsp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_invalid_literal_length_code:\n" "        movl    $2, 116(%%rsp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_invalid_distance_code:\n" "        movl    $3, 116(%%rsp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_invalid_distance_too_far:\n" "        movl    $4, 116(%%rsp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_break_loop:\n" "        movl    $0, 116(%%rsp)\n"  ".L_break_loop_with_status:\n"
comment|/* put in, out, bits, and hold back into ar and pop esp */
asm|"        movq    %%rsi, 16(%%rsp)\n"
comment|/* in */
asm|"        movq    %%rdi, 32(%%rsp)\n"
comment|/* out */
asm|"        movl    %%ebx, 88(%%rsp)\n"
comment|/* bits */
asm|"        movq    %%rdx, 80(%%rsp)\n"
comment|/* hold */
asm|"        movq    (%%rsp), %%rax\n"
comment|/* restore rbp and rsp */
asm|"        movq    8(%%rsp), %%rbp\n" "        movq    %%rax, %%rsp\n"           :           : "m" (ar)           : "memory", "%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi",             "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"     );
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ICC
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|__i386
argument_list|)
asm|__asm__
specifier|__volatile__
asm|( "        leal    %0, %%eax\n" "        movl    %%esp, (%%eax)\n"
comment|/* save esp, ebp */
asm|"        movl    %%ebp, 4(%%eax)\n" "        movl    %%eax, %%esp\n" "        movl    8(%%esp), %%esi\n"
comment|/* esi = in */
asm|"        movl    16(%%esp), %%edi\n"
comment|/* edi = out */
asm|"        movl    40(%%esp), %%edx\n"
comment|/* edx = hold */
asm|"        movl    44(%%esp), %%ebx\n"
comment|/* ebx = bits */
asm|"        movl    32(%%esp), %%ebp\n"
comment|/* ebp = lcode */
asm|"        cld\n" "        jmp     .L_do_loop\n"  ".align 32,0x90\n" ".L_while_test:\n" "        cmpl    %%edi, 24(%%esp)\n"
comment|/* out< end */
asm|"        jbe     .L_break_loop\n" "        cmpl    %%esi, 12(%%esp)\n"
comment|/* in< last */
asm|"        jbe     .L_break_loop\n"  ".L_do_loop:\n" "        cmpb    $15, %%bl\n" "        ja      .L_get_length_code\n"
comment|/* if (15< bits) */
asm|"        xorl    %%eax, %%eax\n" "        lodsw\n"
comment|/* al = *(ushort *)in++ */
asm|"        movb    %%bl, %%cl\n"
comment|/* cl = bits, needs it for shifting */
asm|"        addb    $16, %%bl\n"
comment|/* bits += 16 */
asm|"        shll    %%cl, %%eax\n" "        orl     %%eax, %%edx\n"
comment|/* hold |= *((ushort *)in)++<< bits */
asm|".L_get_length_code:\n" "        movl    56(%%esp), %%eax\n"
comment|/* eax = lmask */
asm|"        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        movl    (%%ebp,%%eax,4), %%eax\n"
comment|/* eax = lcode[hold& lmask] */
asm|".L_dolen:\n" "        movb    %%ah, %%cl\n"
comment|/* cl = this.bits */
asm|"        subb    %%ah, %%bl\n"
comment|/* bits -= this.bits */
asm|"        shrl    %%cl, %%edx\n"
comment|/* hold>>= this.bits */
asm|"        testb   %%al, %%al\n" "        jnz     .L_test_for_length_base\n"
comment|/* if (op != 0) 45.7% */
asm|"        shrl    $16, %%eax\n"
comment|/* output this.val char */
asm|"        stosb\n" "        jmp     .L_while_test\n"  ".align 32,0x90\n" ".L_test_for_length_base:\n" "        movl    %%eax, %%ecx\n"
comment|/* len = this */
asm|"        shrl    $16, %%ecx\n"
comment|/* len = this.val */
asm|"        movl    %%ecx, 64(%%esp)\n"
comment|/* save len */
asm|"        movb    %%al, %%cl\n"  "        testb   $16, %%al\n" "        jz      .L_test_for_second_level_length\n"
comment|/* if ((op& 16) == 0) 8% */
asm|"        andb    $15, %%cl\n"
comment|/* op&= 15 */
asm|"        jz      .L_decode_distance\n"
comment|/* if (!op) */
asm|"        cmpb    %%cl, %%bl\n" "        jae     .L_add_bits_to_len\n"
comment|/* if (op<= bits) */
asm|"        movb    %%cl, %%ch\n"
comment|/* stash op in ch, freeing cl */
asm|"        xorl    %%eax, %%eax\n" "        lodsw\n"
comment|/* al = *(ushort *)in++ */
asm|"        movb    %%bl, %%cl\n"
comment|/* cl = bits, needs it for shifting */
asm|"        addb    $16, %%bl\n"
comment|/* bits += 16 */
asm|"        shll    %%cl, %%eax\n" "        orl     %%eax, %%edx\n"
comment|/* hold |= *((ushort *)in)++<< bits */
asm|"        movb    %%ch, %%cl\n"
comment|/* move op back to ecx */
asm|".L_add_bits_to_len:\n" "        subb    %%cl, %%bl\n" "        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n" "        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        shrl    %%cl, %%edx\n" "        addl    %%eax, 64(%%esp)\n"
comment|/* len += hold& mask[op] */
asm|".L_decode_distance:\n" "        cmpb    $15, %%bl\n" "        ja      .L_get_distance_code\n"
comment|/* if (15< bits) */
asm|"        xorl    %%eax, %%eax\n" "        lodsw\n"
comment|/* al = *(ushort *)in++ */
asm|"        movb    %%bl, %%cl\n"
comment|/* cl = bits, needs it for shifting */
asm|"        addb    $16, %%bl\n"
comment|/* bits += 16 */
asm|"        shll    %%cl, %%eax\n" "        orl     %%eax, %%edx\n"
comment|/* hold |= *((ushort *)in)++<< bits */
asm|".L_get_distance_code:\n" "        movl    60(%%esp), %%eax\n"
comment|/* eax = dmask */
asm|"        movl    36(%%esp), %%ecx\n"
comment|/* ecx = dcode */
asm|"        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        movl    (%%ecx,%%eax,4), %%eax\n"
comment|/* eax = dcode[hold& dmask] */
asm|".L_dodist:\n" "        movl    %%eax, %%ebp\n"
comment|/* dist = this */
asm|"        shrl    $16, %%ebp\n"
comment|/* dist = this.val */
asm|"        movb    %%ah, %%cl\n" "        subb    %%ah, %%bl\n"
comment|/* bits -= this.bits */
asm|"        shrl    %%cl, %%edx\n"
comment|/* hold>>= this.bits */
asm|"        movb    %%al, %%cl\n"
comment|/* cl = this.op */
asm|"        testb   $16, %%al\n"
comment|/* if ((op& 16) == 0) */
asm|"        jz      .L_test_for_second_level_dist\n" "        andb    $15, %%cl\n"
comment|/* op&= 15 */
asm|"        jz      .L_check_dist_one\n" "        cmpb    %%cl, %%bl\n" "        jae     .L_add_bits_to_dist\n"
comment|/* if (op<= bits) 97.6% */
asm|"        movb    %%cl, %%ch\n"
comment|/* stash op in ch, freeing cl */
asm|"        xorl    %%eax, %%eax\n" "        lodsw\n"
comment|/* al = *(ushort *)in++ */
asm|"        movb    %%bl, %%cl\n"
comment|/* cl = bits, needs it for shifting */
asm|"        addb    $16, %%bl\n"
comment|/* bits += 16 */
asm|"        shll    %%cl, %%eax\n" "        orl     %%eax, %%edx\n"
comment|/* hold |= *((ushort *)in)++<< bits */
asm|"        movb    %%ch, %%cl\n"
comment|/* move op back to ecx */
asm|".L_add_bits_to_dist:\n" "        subb    %%cl, %%bl\n" "        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n"
comment|/* (1<< op) - 1 */
asm|"        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        shrl    %%cl, %%edx\n" "        addl    %%eax, %%ebp\n"
comment|/* dist += hold& ((1<< op) - 1) */
asm|".L_check_window:\n" "        movl    %%esi, 8(%%esp)\n"
comment|/* save in so from can use it's reg */
asm|"        movl    %%edi, %%eax\n" "        subl    20(%%esp), %%eax\n"
comment|/* nbytes = out - beg */
asm|"        cmpl    %%ebp, %%eax\n" "        jb      .L_clip_window\n"
comment|/* if (dist> nbytes) 4.2% */
asm|"        movl    64(%%esp), %%ecx\n"
comment|/* ecx = len */
asm|"        movl    %%edi, %%esi\n" "        subl    %%ebp, %%esi\n"
comment|/* from = out - dist */
asm|"        sarl    %%ecx\n" "        jnc     .L_copy_two\n"
comment|/* if len % 2 == 0 */
asm|"        rep     movsw\n" "        movb    (%%esi), %%al\n" "        movb    %%al, (%%edi)\n" "        incl    %%edi\n"  "        movl    8(%%esp), %%esi\n"
comment|/* move in back to %esi, toss from */
asm|"        movl    32(%%esp), %%ebp\n"
comment|/* ebp = lcode */
asm|"        jmp     .L_while_test\n"  ".L_copy_two:\n" "        rep     movsw\n" "        movl    8(%%esp), %%esi\n"
comment|/* move in back to %esi, toss from */
asm|"        movl    32(%%esp), %%ebp\n"
comment|/* ebp = lcode */
asm|"        jmp     .L_while_test\n"  ".align 32,0x90\n" ".L_check_dist_one:\n" "        cmpl    $1, %%ebp\n"
comment|/* if dist 1, is a memset */
asm|"        jne     .L_check_window\n" "        cmpl    %%edi, 20(%%esp)\n" "        je      .L_check_window\n"
comment|/* out == beg, if outside window */
asm|"        movl    64(%%esp), %%ecx\n"
comment|/* ecx = len */
asm|"        movb    -1(%%edi), %%al\n" "        movb    %%al, %%ah\n"  "        sarl    %%ecx\n" "        jnc     .L_set_two\n" "        movb    %%al, (%%edi)\n" "        incl    %%edi\n"  ".L_set_two:\n" "        rep     stosw\n" "        movl    32(%%esp), %%ebp\n"
comment|/* ebp = lcode */
asm|"        jmp     .L_while_test\n"  ".align 32,0x90\n" ".L_test_for_second_level_length:\n" "        testb   $64, %%al\n" "        jnz     .L_test_for_end_of_block\n"
comment|/* if ((op& 64) != 0) */
asm|"        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n" "        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        addl    64(%%esp), %%eax\n"
comment|/* eax += len */
asm|"        movl    (%%ebp,%%eax,4), %%eax\n"
comment|/* eax = lcode[val+(hold&mask[op])]*/
asm|"        jmp     .L_dolen\n"  ".align 32,0x90\n" ".L_test_for_second_level_dist:\n" "        testb   $64, %%al\n" "        jnz     .L_invalid_distance_code\n"
comment|/* if ((op& 64) != 0) */
asm|"        xorl    %%eax, %%eax\n" "        incl    %%eax\n" "        shll    %%cl, %%eax\n" "        decl    %%eax\n" "        andl    %%edx, %%eax\n"
comment|/* eax&= hold */
asm|"        addl    %%ebp, %%eax\n"
comment|/* eax += dist */
asm|"        movl    36(%%esp), %%ecx\n"
comment|/* ecx = dcode */
asm|"        movl    (%%ecx,%%eax,4), %%eax\n"
comment|/* eax = dcode[val+(hold&mask[op])]*/
asm|"        jmp     .L_dodist\n"  ".align 32,0x90\n" ".L_clip_window:\n" "        movl    %%eax, %%ecx\n" "        movl    48(%%esp), %%eax\n"
comment|/* eax = wsize */
asm|"        negl    %%ecx\n"
comment|/* nbytes = -nbytes */
asm|"        movl    28(%%esp), %%esi\n"
comment|/* from = window */
asm|"        cmpl    %%ebp, %%eax\n" "        jb      .L_invalid_distance_too_far\n"
comment|/* if (dist> wsize) */
asm|"        addl    %%ebp, %%ecx\n"
comment|/* nbytes = dist - nbytes */
asm|"        cmpl    $0, 52(%%esp)\n" "        jne     .L_wrap_around_window\n"
comment|/* if (write != 0) */
asm|"        subl    %%ecx, %%eax\n" "        addl    %%eax, %%esi\n"
comment|/* from += wsize - nbytes */
asm|"        movl    64(%%esp), %%eax\n"
comment|/* eax = len */
asm|"        cmpl    %%ecx, %%eax\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* len -= nbytes */
asm|"        rep     movsb\n" "        movl    %%edi, %%esi\n" "        subl    %%ebp, %%esi\n"
comment|/* from = out - dist */
asm|"        jmp     .L_do_copy\n"  ".align 32,0x90\n" ".L_wrap_around_window:\n" "        movl    52(%%esp), %%eax\n"
comment|/* eax = write */
asm|"        cmpl    %%eax, %%ecx\n" "        jbe     .L_contiguous_in_window\n"
comment|/* if (write>= nbytes) */
asm|"        addl    48(%%esp), %%esi\n"
comment|/* from += wsize */
asm|"        addl    %%eax, %%esi\n"
comment|/* from += write */
asm|"        subl    %%ecx, %%esi\n"
comment|/* from -= nbytes */
asm|"        subl    %%eax, %%ecx\n"
comment|/* nbytes -= write */
asm|"        movl    64(%%esp), %%eax\n"
comment|/* eax = len */
asm|"        cmpl    %%ecx, %%eax\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* len -= nbytes */
asm|"        rep     movsb\n" "        movl    28(%%esp), %%esi\n"
comment|/* from = window */
asm|"        movl    52(%%esp), %%ecx\n"
comment|/* nbytes = write */
asm|"        cmpl    %%ecx, %%eax\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* len -= nbytes */
asm|"        rep     movsb\n" "        movl    %%edi, %%esi\n" "        subl    %%ebp, %%esi\n"
comment|/* from = out - dist */
asm|"        jmp     .L_do_copy\n"  ".align 32,0x90\n" ".L_contiguous_in_window:\n" "        addl    %%eax, %%esi\n" "        subl    %%ecx, %%esi\n"
comment|/* from += write - nbytes */
asm|"        movl    64(%%esp), %%eax\n"
comment|/* eax = len */
asm|"        cmpl    %%ecx, %%eax\n" "        jbe     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|"        subl    %%ecx, %%eax\n"
comment|/* len -= nbytes */
asm|"        rep     movsb\n" "        movl    %%edi, %%esi\n" "        subl    %%ebp, %%esi\n"
comment|/* from = out - dist */
asm|"        jmp     .L_do_copy\n"
comment|/* if (nbytes>= len) */
asm|".align 32,0x90\n" ".L_do_copy:\n" "        movl    %%eax, %%ecx\n" "        rep     movsb\n"  "        movl    8(%%esp), %%esi\n"
comment|/* move in back to %esi, toss from */
asm|"        movl    32(%%esp), %%ebp\n"
comment|/* ebp = lcode */
asm|"        jmp     .L_while_test\n"  ".L_test_for_end_of_block:\n" "        testb   $32, %%al\n" "        jz      .L_invalid_literal_length_code\n" "        movl    $1, 72(%%esp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_invalid_literal_length_code:\n" "        movl    $2, 72(%%esp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_invalid_distance_code:\n" "        movl    $3, 72(%%esp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_invalid_distance_too_far:\n" "        movl    8(%%esp), %%esi\n" "        movl    $4, 72(%%esp)\n" "        jmp     .L_break_loop_with_status\n"  ".L_break_loop:\n" "        movl    $0, 72(%%esp)\n"  ".L_break_loop_with_status:\n"
comment|/* put in, out, bits, and hold back into ar and pop esp */
asm|"        movl    %%esi, 8(%%esp)\n"
comment|/* save in */
asm|"        movl    %%edi, 16(%%esp)\n"
comment|/* save out */
asm|"        movl    %%ebx, 44(%%esp)\n"
comment|/* save bits */
asm|"        movl    %%edx, 40(%%esp)\n"
comment|/* save hold */
asm|"        movl    4(%%esp), %%ebp\n"
comment|/* restore esp, ebp */
asm|"        movl    (%%esp), %%esp\n"           :           : "m" (ar)           : "memory", "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi"     );
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_M_AMD64
argument_list|)
asm|__asm {
asm|lea	eax, ar
asm|mov	[eax], esp
comment|/* save esp, ebp */
asm|mov	[eax+4], ebp
asm|mov	esp, eax
asm|mov	esi, [esp+8]
comment|/* esi = in */
asm|mov	edi, [esp+16]
comment|/* edi = out */
asm|mov	edx, [esp+40]
comment|/* edx = hold */
asm|mov	ebx, [esp+44]
comment|/* ebx = bits */
asm|mov	ebp, [esp+32]
comment|/* ebp = lcode */
asm|cld
asm|jmp	L_do_loop
asm|ALIGN 4
asm|L_while_test:
asm|cmp	[esp+24], edi
asm|jbe	L_break_loop
asm|cmp	[esp+12], esi
asm|jbe	L_break_loop
asm|L_do_loop:
asm|cmp	bl, 15
asm|ja	L_get_length_code
comment|/* if (15< bits) */
asm|xor	eax, eax
asm|lodsw
comment|/* al = *(ushort *)in++ */
asm|mov	cl, bl
comment|/* cl = bits, needs it for shifting */
asm|add	bl, 16
comment|/* bits += 16 */
asm|shl	eax, cl
asm|or	edx, eax
comment|/* hold |= *((ushort *)in)++<< bits */
asm|L_get_length_code:
asm|mov	eax, [esp+56]
comment|/* eax = lmask */
asm|and	eax, edx
comment|/* eax&= hold */
asm|mov	eax, [ebp+eax*4]
comment|/* eax = lcode[hold& lmask] */
asm|L_dolen:
asm|mov	cl, ah
comment|/* cl = this.bits */
asm|sub	bl, ah
comment|/* bits -= this.bits */
asm|shr	edx, cl
comment|/* hold>>= this.bits */
asm|test	al, al
asm|jnz	L_test_for_length_base
comment|/* if (op != 0) 45.7% */
asm|shr	eax, 16
comment|/* output this.val char */
asm|stosb
asm|jmp	L_while_test
asm|ALIGN 4
asm|L_test_for_length_base:
asm|mov	ecx, eax
comment|/* len = this */
asm|shr	ecx, 16
comment|/* len = this.val */
asm|mov	[esp+64], ecx
comment|/* save len */
asm|mov	cl, al
asm|test	al, 16
asm|jz	L_test_for_second_level_length
comment|/* if ((op& 16) == 0) 8% */
asm|and	cl, 15
comment|/* op&= 15 */
asm|jz	L_decode_distance
comment|/* if (!op) */
asm|cmp	bl, cl
asm|jae	L_add_bits_to_len
comment|/* if (op<= bits) */
asm|mov	ch, cl
comment|/* stash op in ch, freeing cl */
asm|xor	eax, eax
asm|lodsw
comment|/* al = *(ushort *)in++ */
asm|mov	cl, bl
comment|/* cl = bits, needs it for shifting */
asm|add	bl, 16
comment|/* bits += 16 */
asm|shl	eax, cl
asm|or	edx, eax
comment|/* hold |= *((ushort *)in)++<< bits */
asm|mov	cl, ch
comment|/* move op back to ecx */
asm|L_add_bits_to_len:
asm|sub	bl, cl
asm|xor	eax, eax
asm|inc	eax
asm|shl	eax, cl
asm|dec	eax
asm|and	eax, edx
comment|/* eax&= hold */
asm|shr	edx, cl
asm|add	[esp+64], eax
comment|/* len += hold& mask[op] */
asm|L_decode_distance:
asm|cmp	bl, 15
asm|ja	L_get_distance_code
comment|/* if (15< bits) */
asm|xor	eax, eax
asm|lodsw
comment|/* al = *(ushort *)in++ */
asm|mov	cl, bl
comment|/* cl = bits, needs it for shifting */
asm|add	bl, 16
comment|/* bits += 16 */
asm|shl	eax, cl
asm|or	edx, eax
comment|/* hold |= *((ushort *)in)++<< bits */
asm|L_get_distance_code:
asm|mov	eax, [esp+60]
comment|/* eax = dmask */
asm|mov	ecx, [esp+36]
comment|/* ecx = dcode */
asm|and	eax, edx
comment|/* eax&= hold */
asm|mov	eax, [ecx+eax*4]
comment|/* eax = dcode[hold& dmask] */
asm|L_dodist:
asm|mov	ebp, eax
comment|/* dist = this */
asm|shr	ebp, 16
comment|/* dist = this.val */
asm|mov	cl, ah
asm|sub	bl, ah
comment|/* bits -= this.bits */
asm|shr	edx, cl
comment|/* hold>>= this.bits */
asm|mov	cl, al
comment|/* cl = this.op */
asm|test	al, 16
comment|/* if ((op& 16) == 0) */
asm|jz	L_test_for_second_level_dist
asm|and	cl, 15
comment|/* op&= 15 */
asm|jz	L_check_dist_one
asm|cmp	bl, cl
asm|jae	L_add_bits_to_dist
comment|/* if (op<= bits) 97.6% */
asm|mov	ch, cl
comment|/* stash op in ch, freeing cl */
asm|xor	eax, eax
asm|lodsw
comment|/* al = *(ushort *)in++ */
asm|mov	cl, bl
comment|/* cl = bits, needs it for shifting */
asm|add	bl, 16
comment|/* bits += 16 */
asm|shl	eax, cl
asm|or	edx, eax
comment|/* hold |= *((ushort *)in)++<< bits */
asm|mov	cl, ch
comment|/* move op back to ecx */
asm|L_add_bits_to_dist:
asm|sub	bl, cl
asm|xor	eax, eax
asm|inc	eax
asm|shl	eax, cl
asm|dec	eax
comment|/* (1<< op) - 1 */
asm|and	eax, edx
comment|/* eax&= hold */
asm|shr	edx, cl
asm|add	ebp, eax
comment|/* dist += hold& ((1<< op) - 1) */
asm|L_check_window:
asm|mov	[esp+8], esi
comment|/* save in so from can use it's reg */
asm|mov	eax, edi
asm|sub	eax, [esp+20]
comment|/* nbytes = out - beg */
asm|cmp	eax, ebp
asm|jb	L_clip_window
comment|/* if (dist> nbytes) 4.2% */
asm|mov	ecx, [esp+64]
comment|/* ecx = len */
asm|mov	esi, edi
asm|sub	esi, ebp
comment|/* from = out - dist */
asm|sar	ecx, 1
asm|jnc	L_copy_two
asm|rep     movsw
asm|mov	al, [esi]
asm|mov	[edi], al
asm|inc	edi
asm|mov	esi, [esp+8]
comment|/* move in back to %esi, toss from */
asm|mov	ebp, [esp+32]
comment|/* ebp = lcode */
asm|jmp	L_while_test
asm|L_copy_two:
asm|rep     movsw
asm|mov	esi, [esp+8]
comment|/* move in back to %esi, toss from */
asm|mov	ebp, [esp+32]
comment|/* ebp = lcode */
asm|jmp	L_while_test
asm|ALIGN 4
asm|L_check_dist_one:
asm|cmp	ebp, 1
comment|/* if dist 1, is a memset */
asm|jne	L_check_window
asm|cmp	[esp+20], edi
asm|je	L_check_window
comment|/* out == beg, if outside window */
asm|mov	ecx, [esp+64]
comment|/* ecx = len */
asm|mov	al, [edi-1]
asm|mov	ah, al
asm|sar	ecx, 1
asm|jnc	L_set_two
asm|mov	[edi], al
comment|/* memset out with from[-1] */
asm|inc	edi
asm|L_set_two:
asm|rep     stosw
asm|mov	ebp, [esp+32]
comment|/* ebp = lcode */
asm|jmp	L_while_test
asm|ALIGN 4
asm|L_test_for_second_level_length:
asm|test	al, 64
asm|jnz	L_test_for_end_of_block
comment|/* if ((op& 64) != 0) */
asm|xor	eax, eax
asm|inc	eax
asm|shl	eax, cl
asm|dec	eax
asm|and	eax, edx
comment|/* eax&= hold */
asm|add	eax, [esp+64]
comment|/* eax += len */
asm|mov	eax, [ebp+eax*4]
comment|/* eax = lcode[val+(hold&mask[op])]*/
asm|jmp	L_dolen
asm|ALIGN 4
asm|L_test_for_second_level_dist:
asm|test	al, 64
asm|jnz	L_invalid_distance_code
comment|/* if ((op& 64) != 0) */
asm|xor	eax, eax
asm|inc	eax
asm|shl	eax, cl
asm|dec	eax
asm|and	eax, edx
comment|/* eax&= hold */
asm|add	eax, ebp
comment|/* eax += dist */
asm|mov	ecx, [esp+36]
comment|/* ecx = dcode */
asm|mov	eax, [ecx+eax*4]
comment|/* eax = dcode[val+(hold&mask[op])]*/
asm|jmp	L_dodist
asm|ALIGN 4
asm|L_clip_window:
asm|mov	ecx, eax
asm|mov	eax, [esp+48]
comment|/* eax = wsize */
asm|neg	ecx
comment|/* nbytes = -nbytes */
asm|mov	esi, [esp+28]
comment|/* from = window */
asm|cmp	eax, ebp
asm|jb	L_invalid_distance_too_far
comment|/* if (dist> wsize) */
asm|add	ecx, ebp
comment|/* nbytes = dist - nbytes */
asm|cmp	dword ptr [esp+52], 0
asm|jne	L_wrap_around_window
comment|/* if (write != 0) */
asm|sub	eax, ecx
asm|add	esi, eax
comment|/* from += wsize - nbytes */
asm|mov	eax, [esp+64]
comment|/* eax = len */
asm|cmp	eax, ecx
asm|jbe	L_do_copy
comment|/* if (nbytes>= len) */
asm|sub	eax, ecx
comment|/* len -= nbytes */
asm|rep     movsb
asm|mov	esi, edi
asm|sub	esi, ebp
comment|/* from = out - dist */
asm|jmp	L_do_copy
asm|ALIGN 4
asm|L_wrap_around_window:
asm|mov	eax, [esp+52]
comment|/* eax = write */
asm|cmp	ecx, eax
asm|jbe	L_contiguous_in_window
comment|/* if (write>= nbytes) */
asm|add	esi, [esp+48]
comment|/* from += wsize */
asm|add	esi, eax
comment|/* from += write */
asm|sub	esi, ecx
comment|/* from -= nbytes */
asm|sub	ecx, eax
comment|/* nbytes -= write */
asm|mov	eax, [esp+64]
comment|/* eax = len */
asm|cmp	eax, ecx
asm|jbe	L_do_copy
comment|/* if (nbytes>= len) */
asm|sub	eax, ecx
comment|/* len -= nbytes */
asm|rep     movsb
asm|mov	esi, [esp+28]
comment|/* from = window */
asm|mov	ecx, [esp+52]
comment|/* nbytes = write */
asm|cmp	eax, ecx
asm|jbe	L_do_copy
comment|/* if (nbytes>= len) */
asm|sub	eax, ecx
comment|/* len -= nbytes */
asm|rep     movsb
asm|mov	esi, edi
asm|sub	esi, ebp
comment|/* from = out - dist */
asm|jmp	L_do_copy
asm|ALIGN 4
asm|L_contiguous_in_window:
asm|add	esi, eax
asm|sub	esi, ecx
comment|/* from += write - nbytes */
asm|mov	eax, [esp+64]
comment|/* eax = len */
asm|cmp	eax, ecx
asm|jbe	L_do_copy
comment|/* if (nbytes>= len) */
asm|sub	eax, ecx
comment|/* len -= nbytes */
asm|rep     movsb
asm|mov	esi, edi
asm|sub	esi, ebp
comment|/* from = out - dist */
asm|jmp	L_do_copy
asm|ALIGN 4
asm|L_do_copy:
asm|mov	ecx, eax
asm|rep     movsb
asm|mov	esi, [esp+8]
comment|/* move in back to %esi, toss from */
asm|mov	ebp, [esp+32]
comment|/* ebp = lcode */
asm|jmp	L_while_test
asm|L_test_for_end_of_block:
asm|test	al, 32
asm|jz	L_invalid_literal_length_code
asm|mov	dword ptr [esp+72], 1
asm|jmp	L_break_loop_with_status
asm|L_invalid_literal_length_code:
asm|mov	dword ptr [esp+72], 2
asm|jmp	L_break_loop_with_status
asm|L_invalid_distance_code:
asm|mov	dword ptr [esp+72], 3
asm|jmp	L_break_loop_with_status
asm|L_invalid_distance_too_far:
asm|mov	esi, [esp+4]
asm|mov	dword ptr [esp+72], 4
asm|jmp	L_break_loop_with_status
asm|L_break_loop:
asm|mov	dword ptr [esp+72], 0
asm|L_break_loop_with_status:
comment|/* put in, out, bits, and hold back into ar and pop esp */
asm|mov	[esp+8], esi
comment|/* save in */
asm|mov	[esp+16], edi
comment|/* save out */
asm|mov	[esp+44], ebx
comment|/* save bits */
asm|mov	[esp+40], edx
comment|/* save hold */
asm|mov	ebp, [esp+4]
comment|/* restore esp, ebp */
asm|mov	esp, [esp]
asm|}
else|#
directive|else
error|#
directive|error
literal|"x86 architecture not defined"
endif|#
directive|endif
if|if
condition|(
name|ar
operator|.
name|status
operator|>
literal|1
condition|)
block|{
if|if
condition|(
name|ar
operator|.
name|status
operator|==
literal|2
condition|)
name|strm
operator|->
name|msg
operator|=
literal|"invalid literal/length code"
expr_stmt|;
elseif|else
if|if
condition|(
name|ar
operator|.
name|status
operator|==
literal|3
condition|)
name|strm
operator|->
name|msg
operator|=
literal|"invalid distance code"
expr_stmt|;
else|else
name|strm
operator|->
name|msg
operator|=
literal|"invalid distance too far back"
expr_stmt|;
name|state
operator|->
name|mode
operator|=
name|BAD
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ar
operator|.
name|status
operator|==
literal|1
condition|)
block|{
name|state
operator|->
name|mode
operator|=
name|TYPE
expr_stmt|;
block|}
comment|/* return unused bytes (on entry, bits< 8, so in won't go too far back) */
name|ar
operator|.
name|len
operator|=
name|ar
operator|.
name|bits
operator|>>
literal|3
expr_stmt|;
name|ar
operator|.
name|in
operator|-=
name|ar
operator|.
name|len
expr_stmt|;
name|ar
operator|.
name|bits
operator|-=
name|ar
operator|.
name|len
operator|<<
literal|3
expr_stmt|;
name|ar
operator|.
name|hold
operator|&=
operator|(
literal|1U
operator|<<
name|ar
operator|.
name|bits
operator|)
operator|-
literal|1
expr_stmt|;
comment|/* update state and return */
name|strm
operator|->
name|next_in
operator|=
name|ar
operator|.
name|in
expr_stmt|;
name|strm
operator|->
name|next_out
operator|=
name|ar
operator|.
name|out
expr_stmt|;
name|strm
operator|->
name|avail_in
operator|=
call|(
name|unsigned
call|)
argument_list|(
name|ar
operator|.
name|in
operator|<
name|ar
operator|.
name|last
condition|?
name|PAD_AVAIL_IN
operator|+
operator|(
name|ar
operator|.
name|last
operator|-
name|ar
operator|.
name|in
operator|)
else|:
name|PAD_AVAIL_IN
operator|-
operator|(
name|ar
operator|.
name|in
operator|-
name|ar
operator|.
name|last
operator|)
argument_list|)
expr_stmt|;
name|strm
operator|->
name|avail_out
operator|=
call|(
name|unsigned
call|)
argument_list|(
name|ar
operator|.
name|out
operator|<
name|ar
operator|.
name|end
condition|?
name|PAD_AVAIL_OUT
operator|+
operator|(
name|ar
operator|.
name|end
operator|-
name|ar
operator|.
name|out
operator|)
else|:
name|PAD_AVAIL_OUT
operator|-
operator|(
name|ar
operator|.
name|out
operator|-
name|ar
operator|.
name|end
operator|)
argument_list|)
expr_stmt|;
name|state
operator|->
name|hold
operator|=
name|ar
operator|.
name|hold
expr_stmt|;
name|state
operator|->
name|bits
operator|=
name|ar
operator|.
name|bits
expr_stmt|;
return|return;
block|}
end_function

end_unit

