begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|"bn_lcl.h"
end_include

begin_define
define|#
directive|define
name|SIZE
value|32
end_define

begin_define
define|#
directive|define
name|BN_MONT_CTX_set
value|bn_mcs
end_define

begin_define
define|#
directive|define
name|BN_from_montgomery
value|bn_fm
end_define

begin_define
define|#
directive|define
name|BN_mod_mul_montgomery
value|bn_mmm
end_define

begin_undef
undef|#
directive|undef
name|BN_to_montgomery
end_undef

begin_define
define|#
directive|define
name|BN_to_montgomery
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|,
name|mont
parameter_list|,
name|ctx
parameter_list|)
value|bn_mmm(\ 	r,a,(mont)->RR,(mont),ctx)
end_define

begin_function
name|main
parameter_list|()
block|{
name|BIGNUM
name|prime
decl_stmt|,
name|a
decl_stmt|,
name|b
decl_stmt|,
name|r
decl_stmt|,
name|A
decl_stmt|,
name|B
decl_stmt|,
name|R
decl_stmt|;
name|BN_MONT_CTX
modifier|*
name|mont
decl_stmt|;
name|BN_CTX
modifier|*
name|ctx
decl_stmt|;
name|int
name|i
decl_stmt|;
name|ctx
operator|=
name|BN_CTX_new
argument_list|()
expr_stmt|;
name|BN_init
argument_list|(
operator|&
name|prime
argument_list|)
expr_stmt|;
name|BN_init
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
name|BN_init
argument_list|(
operator|&
name|b
argument_list|)
expr_stmt|;
name|BN_init
argument_list|(
operator|&
name|r
argument_list|)
expr_stmt|;
name|BN_init
argument_list|(
operator|&
name|A
argument_list|)
expr_stmt|;
name|BN_init
argument_list|(
operator|&
name|B
argument_list|)
expr_stmt|;
name|BN_init
argument_list|(
operator|&
name|R
argument_list|)
expr_stmt|;
name|BN_generate_prime
argument_list|(
operator|&
name|prime
argument_list|,
name|SIZE
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|BN_rand
argument_list|(
operator|&
name|A
argument_list|,
name|SIZE
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|BN_rand
argument_list|(
operator|&
name|B
argument_list|,
name|SIZE
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|BN_mod
argument_list|(
operator|&
name|A
argument_list|,
operator|&
name|A
argument_list|,
operator|&
name|prime
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
name|BN_mod
argument_list|(
operator|&
name|B
argument_list|,
operator|&
name|B
argument_list|,
operator|&
name|prime
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
name|i
operator|=
name|A
operator|.
name|top
expr_stmt|;
name|BN_mul
argument_list|(
operator|&
name|R
argument_list|,
operator|&
name|A
argument_list|,
operator|&
name|B
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
name|BN_mask_bits
argument_list|(
operator|&
name|R
argument_list|,
name|i
operator|*
name|BN_BITS2
argument_list|)
expr_stmt|;
name|BN_print_fp
argument_list|(
name|stdout
argument_list|,
operator|&
name|A
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"<- a\n"
argument_list|)
expr_stmt|;
name|BN_print_fp
argument_list|(
name|stdout
argument_list|,
operator|&
name|B
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"<- b\n"
argument_list|)
expr_stmt|;
name|BN_mul_high
argument_list|(
operator|&
name|r
argument_list|,
operator|&
name|A
argument_list|,
operator|&
name|B
argument_list|,
operator|&
name|R
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|BN_print_fp
argument_list|(
name|stdout
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"<- high(BA*DC)\n"
argument_list|)
expr_stmt|;
name|BN_mask_bits
argument_list|(
operator|&
name|A
argument_list|,
name|i
operator|*
literal|32
argument_list|)
expr_stmt|;
name|BN_mask_bits
argument_list|(
operator|&
name|B
argument_list|,
name|i
operator|*
literal|32
argument_list|)
expr_stmt|;
name|BN_mul
argument_list|(
operator|&
name|R
argument_list|,
operator|&
name|A
argument_list|,
operator|&
name|B
argument_list|)
expr_stmt|;
name|BN_rshift
argument_list|(
operator|&
name|R
argument_list|,
operator|&
name|R
argument_list|,
name|i
operator|*
literal|32
argument_list|)
expr_stmt|;
name|BN_print_fp
argument_list|(
name|stdout
argument_list|,
operator|&
name|R
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"<- norm BA*DC\n"
argument_list|)
expr_stmt|;
name|BN_sub
argument_list|(
operator|&
name|R
argument_list|,
operator|&
name|R
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
name|BN_print_fp
argument_list|(
name|stdout
argument_list|,
operator|&
name|R
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"<- diff\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|int bn_mul_high(BIGNUM *r, BIGNUM *a, BIGNUM *b, BIGNUM *low, int words) 	{ 	int i; 	BIGNUM t1,t2,t3,h,ah,al,bh,bl,m,s0,s1;  	BN_init(&al); BN_init(&ah); 	BN_init(&bl); BN_init(&bh); 	BN_init(&t1); BN_init(&t2); BN_init(&t3); 	BN_init(&s0); BN_init(&s1); 	BN_init(&h); BN_init(&m);  	i=a->top; 	if (i>= words) 		{ 		al.top=words; 		ah.top=a->top-words; 		ah.d=&(a->d[ah.top]); 		} 	else 		al.top=i; 	al.d=a->d;  	i=b->top; 	if (i>= words) 		{ 		bl.top=words; 		bh.top=i-words; 		bh.d=&(b->d[bh.top]); 		} 	else 		bl.top=i; 	bl.d=b->d;  	i=low->top; 	if (i>= words) 		{ 		s0.top=words; 		s1.top=i-words; 		s1.d=&(low->d[s1.top]); 		} 	else 		s0.top=i; 	s0.d=low->d;  al.max=al.top; ah.max=ah.top; bl.max=bl.top; bh.max=bh.top; s0.max=bl.top; s1.max=bh.top;
comment|/* Calculate (al-ah)*(bh-bl) */
end_comment

begin_comment
unit|BN_sub(&t1,&al,&ah); 	BN_sub(&t2,&bh,&bl); 	BN_mul(&m,&t1,&t2);
comment|/* Calculate ah*bh */
end_comment

begin_comment
unit|BN_mul(&h,&ah,&bh);
comment|/* s0 == low(al*bl) 	 * s1 == low(ah*bh)+low((al-ah)*(bh-bl))+low(al*bl)+high(al*bl) 	 * We know s0 and s1 so the only unknown is high(al*bl) 	 * high(al*bl) == s1 - low(ah*bh+(al-ah)*(bh-bl)+s0) 	 */
end_comment

begin_comment
unit|BN_add(&m,&m,&h); 	BN_add(&t2,&m,&s0);
comment|/* Quick and dirty mask off of high words */
end_comment

begin_comment
unit|t3.d=t2.d; 	t3.top=(t2.top> words)?words:t2.top; 	t3.neg=t2.neg; t3.max=t3.top;
comment|/* BN_print_fp(stdout,&s1); printf(" s1\n"); */
end_comment

begin_comment
comment|/* BN_print_fp(stdout,&t2); printf(" middle value\n"); */
end_comment

begin_comment
comment|/* BN_print_fp(stdout,&t3); printf(" low middle value\n"); */
end_comment

begin_comment
unit|BN_sub(&t1,&s1,&t3);  	if (t1.neg) 		{
comment|/*printf("neg fixup\n"); BN_print_fp(stdout,&t1); printf(" before\n"); */
end_comment

begin_comment
unit|BN_lshift(&t2,BN_value_one(),words*32); 		BN_add(&t1,&t2,&t1); 		BN_mask_bits(&t1,words*32);
comment|/* BN_print_fp(stdout,&t1); printf(" after\n"); */
end_comment

begin_comment
unit|}
comment|/* al*bl == high(al*bl)<<words+s0 */
end_comment

begin_comment
unit|BN_lshift(&t1,&t1,words*32); 	BN_add(&t1,&t1,&s0);
comment|/* We now have 	 * al*bl			- t1 	 * (al-ah)*(bh-bl)+ah*bh	- m 	 * ah*bh			- h 	 */
end_comment

begin_comment
unit|BN_copy(r,&t1); 	BN_mask_bits(r,words*32*2);
comment|/*BN_lshift(&m,&m,words*/
end_comment

begin_comment
unit|BN_free(&t1); BN_free(&t2); 	BN_free(&m); BN_free(&h); 	}  int BN_mod_mul_montgomery(BIGNUM *r, BIGNUM *a, BIGNUM *b, BN_MONT_CTX *mont, 	     BN_CTX *ctx) 	{ 	BIGNUM *tmp;          tmp=&(ctx->bn[ctx->tos++]);  	if (a == b) 		{ 		if (!BN_sqr(tmp,a,ctx)) goto err; 		} 	else 		{ 		if (!BN_mul(tmp,a,b)) goto err; 		}
comment|/* reduce from aRR to aR */
end_comment

begin_comment
unit|if (!BN_from_montgomery(r,tmp,mont,ctx)) goto err; 	ctx->tos--; 	return(1); err: 	return(0); 	}  int BN_from_montgomery(BIGNUM *r, BIGNUM *a, BN_MONT_CTX *mont, BN_CTX *ctx) 	{ 	BIGNUM z1; 	BIGNUM *t1,*t2; 	BN_ULONG *ap,*bp,*rp; 	int j,i,bl,al;  	BN_init(&z1); 	t1=&(ctx->bn[ctx->tos]); 	t2=&(ctx->bn[ctx->tos+1]);  	if (!BN_copy(t1,a)) goto err;
comment|/* can cheat */
end_comment

begin_comment
unit|BN_mask_bits(t1,mont->ri); 	if (!BN_mul(t2,t1,mont->Ni)) goto err; 	BN_mask_bits(t2,mont->ri);  	if (!BN_mul(t1,t2,mont->N)) goto err; 	if (!BN_add(t2,t1,a)) goto err;
comment|/* At this point, t2 has the bottom ri bits set to zero. 	 * This means that the bottom ri bits == the 1^ri minus the bottom 	 * ri bits of a. 	 * This means that only the bits above 'ri' in a need to be added, 	 * and XXXXXXXXXXXXXXXXXXXXXXXX 	 */
end_comment

begin_comment
unit|BN_print_fp(stdout,t2); printf("\n"); 	BN_rshift(r,t2,mont->ri);  	if (BN_ucmp(r,mont->N)>= 0) 		BN_usub(r,r,mont->N);  	return(1); err: 	return(0); 	}  int BN_MONT_CTX_set(BN_MONT_CTX *mont, BIGNUM *mod, BN_CTX *ctx) 	{ 	BIGNUM *Ri=NULL,*R=NULL;  	if (mont->RR == NULL) mont->RR=BN_new(); 	if (mont->N == NULL)  mont->N=BN_new();  	R=mont->RR;
comment|/* grab RR as a temp */
end_comment

begin_comment
unit|BN_copy(mont->N,mod);
comment|/* Set N */
end_comment

begin_comment
unit|mont->ri=(BN_num_bits(mod)+(BN_BITS2-1))/BN_BITS2*BN_BITS2; 	BN_lshift(R,BN_value_one(),mont->ri);
comment|/* R */
end_comment

begin_comment
unit|if ((Ri=BN_mod_inverse(NULL,R,mod,ctx)) == NULL) goto err;
comment|/* Ri */
end_comment

begin_comment
unit|BN_lshift(Ri,Ri,mont->ri);
comment|/* R*Ri */
end_comment

begin_comment
unit|BN_usub(Ri,Ri,BN_value_one());
comment|/* R*Ri - 1 */
end_comment

begin_comment
unit|BN_div(Ri,NULL,Ri,mod,ctx); 	if (mont->Ni != NULL) BN_free(mont->Ni); 	mont->Ni=Ri;
comment|/* Ni=(R*Ri-1)/N */
end_comment

begin_comment
comment|/* setup RR for conversions */
end_comment

begin_endif
unit|BN_lshift(mont->RR,BN_value_one(),mont->ri*2); 	BN_mod(mont->RR,mont->RR,mont->N,ctx);  	return(1); err: 	return(0); 	}
endif|#
directive|endif
end_endif

end_unit

