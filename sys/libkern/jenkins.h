begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__LIBKERN_JENKINS_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIBKERN_JENKINS_H__
end_define

begin_comment
comment|/*  * Taken from http://burtleburtle.net/bob/c/lookup3.c  * $FreeBSD$  */
end_comment

begin_comment
comment|/* -------------------------------------------------------------------------------   lookup3.c, by Bob Jenkins, May 2006, Public Domain.    These are functions for producing 32-bit hashes for hash table lookup.   hashword(), hashlittle(), hashlittle2(), hashbig(), mix(), and final()   are externally useful functions.  Routines to test the hash are included   if SELF_TEST is defined.  You can use this free for any purpose.  It's in   the public domain.  It has no warranty.    You probably want to use hashlittle().  hashlittle() and hashbig()   hash byte arrays.  hashlittle() is faster than hashbig() on   little-endian machines.  Intel and AMD are little-endian machines.   On second thought, you probably want hashlittle2(), which is identical to   hashlittle() except it returns two 32-bit hashes for the price of one.   You could implement hashbig2() if you wanted but I haven't bothered here.    If you want to find a hash of, say, exactly 7 integers, do     a = i1;  b = i2;  c = i3;     mix(a,b,c);     a += i4; b += i5; c += i6;     mix(a,b,c);     a += i7;     final(a,b,c);   then use c as the hash value.  If you have a variable length array of   4-byte integers to hash, use hashword().  If you have a byte array (like   a character string), use hashlittle().  If you have several byte arrays, or   a mix of things, see the comments above hashlittle().      Why is this so big?  I read 12 bytes at a time into 3 4-byte integers,   then mix those integers.  This is fast (you can do a lot more thorough   mixing with 12*3 instructions on 3 integers than you can with 3 instructions   on 1 byte), but shoehorning those bytes into integers efficiently is messy. ------------------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|rot
parameter_list|(
name|x
parameter_list|,
name|k
parameter_list|)
value|(((x)<<(k)) | ((x)>>(32-(k))))
end_define

begin_comment
comment|/* ------------------------------------------------------------------------------- mix -- mix 3 32-bit values reversibly.  This is reversible, so any information in (a,b,c) before mix() is still in (a,b,c) after mix().  If four pairs of (a,b,c) inputs are run through mix(), or through mix() in reverse, there are at least 32 bits of the output that are sometimes the same for one pair and different for another pair. This was tested for: * pairs that differed by one bit, by two bits, in any combination   of top bits of (a,b,c), or in any combination of bottom bits of   (a,b,c). * "differ" is defined as +, -, ^, or ~^.  For + and -, I transformed   the output delta to a Gray code (a^(a>>1)) so a string of 1's (as   is commonly produced by subtraction) look like a single 1-bit   difference. * the base values were pseudorandom, all zero but one bit set, or    all zero plus a counter that starts at zero.  Some k values for my "a-=c; a^=rot(c,k); c+=b;" arrangement that satisfy this are     4  6  8 16 19  4     9 15  3 18 27 15    14  9  3  7 17  3 Well, "9 15 3 18 27 15" didn't quite get 32 bits diffing for "differ" defined as + with a one-bit base and a two-bit delta.  I used http://burtleburtle.net/bob/hash/avalanche.html to choose  the operations, constants, and arrangements of the variables.  This does not achieve avalanche.  There are input bits of (a,b,c) that fail to affect some output bits of (a,b,c), especially of a.  The most thoroughly mixed value is c, but it doesn't really even achieve avalanche in c.  This allows some parallelism.  Read-after-writes are good at doubling the number of bits affected, so the goal of mixing pulls in the opposite direction as the goal of parallelism.  I did what I could.  Rotates seem to cost as much as shifts on every machine I could lay my hands on, and rotates are much kinder to the top and bottom bits, so I used rotates. ------------------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|mix
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|{ \   a -= c;  a ^= rot(c, 4);  c += b; \   b -= a;  b ^= rot(a, 6);  a += c; \   c -= b;  c ^= rot(b, 8);  b += a; \   a -= c;  a ^= rot(c,16);  c += b; \   b -= a;  b ^= rot(a,19);  a += c; \   c -= b;  c ^= rot(b, 4);  b += a; \ }
end_define

begin_comment
comment|/* ------------------------------------------------------------------------------- final -- final mixing of 3 32-bit values (a,b,c) into c  Pairs of (a,b,c) values differing in only a few bits will usually produce values of c that look totally different.  This was tested for * pairs that differed by one bit, by two bits, in any combination   of top bits of (a,b,c), or in any combination of bottom bits of   (a,b,c). * "differ" is defined as +, -, ^, or ~^.  For + and -, I transformed   the output delta to a Gray code (a^(a>>1)) so a string of 1's (as   is commonly produced by subtraction) look like a single 1-bit   difference. * the base values were pseudorandom, all zero but one bit set, or    all zero plus a counter that starts at zero.  These constants passed:  14 11 25 16 4 14 24  12 14 25 16 4 14 24 and these came close:   4  8 15 26 3 22 24  10  8 15 26 3 22 24  11  8 15 26 3 22 24 ------------------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|final
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|{ \   c ^= b; c -= rot(b,14); \   a ^= c; a -= rot(c,11); \   b ^= a; b -= rot(a,25); \   c ^= b; c -= rot(b,16); \   a ^= c; a -= rot(c,4);  \   b ^= a; b -= rot(a,14); \   c ^= b; c -= rot(b,24); \ }
end_define

begin_comment
comment|/* --------------------------------------------------------------------  This works on all machines.  To be useful, it requires  -- that the key be an array of uint32_t's, and  -- that the length be the number of uint32_t's in the key   The function hashword() is identical to hashlittle() on little-endian  machines, and identical to hashbig() on big-endian machines,  except that the length has to be measured in uint32_ts rather than in  bytes.  hashlittle() is more complicated than hashword() only because  hashlittle() has to dance around fitting the key bytes into registers. -------------------------------------------------------------------- */
end_comment

begin_function
specifier|static
name|uint32_t
name|jenkins_hashword
parameter_list|(
specifier|const
name|uint32_t
modifier|*
name|k
parameter_list|,
comment|/* the key, an array of uint32_t values */
name|size_t
name|length
parameter_list|,
comment|/* the length of the key, in uint32_ts */
name|uint32_t
name|initval
comment|/* the previous hash, or an arbitrary value */
parameter_list|)
block|{
name|uint32_t
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
comment|/* Set up the internal state */
name|a
operator|=
name|b
operator|=
name|c
operator|=
literal|0xdeadbeef
operator|+
operator|(
operator|(
operator|(
name|uint32_t
operator|)
name|length
operator|)
operator|<<
literal|2
operator|)
operator|+
name|initval
expr_stmt|;
comment|/*------------------------------------------------- handle most of the key */
while|while
condition|(
name|length
operator|>
literal|3
condition|)
block|{
name|a
operator|+=
name|k
index|[
literal|0
index|]
expr_stmt|;
name|b
operator|+=
name|k
index|[
literal|1
index|]
expr_stmt|;
name|c
operator|+=
name|k
index|[
literal|2
index|]
expr_stmt|;
name|mix
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|length
operator|-=
literal|3
expr_stmt|;
name|k
operator|+=
literal|3
expr_stmt|;
block|}
comment|/*------------------------------------------- handle the last 3 uint32_t's */
switch|switch
condition|(
name|length
condition|)
comment|/* all the case statements fall through */
block|{
case|case
literal|3
case|:
name|c
operator|+=
name|k
index|[
literal|2
index|]
expr_stmt|;
case|case
literal|2
case|:
name|b
operator|+=
name|k
index|[
literal|1
index|]
expr_stmt|;
case|case
literal|1
case|:
name|a
operator|+=
name|k
index|[
literal|0
index|]
expr_stmt|;
name|final
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
case|case
literal|0
case|:
comment|/* case 0: nothing left to add */
break|break;
block|}
comment|/*------------------------------------------------------ report the result */
return|return
name|c
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

