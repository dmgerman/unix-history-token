begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"apl.h"
end_include

begin_macro
name|asciich
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|unsigned
name|char
modifier|*
name|iline
decl_stmt|;
specifier|extern
name|struct
name|asoperbox
name|charconv
index|[
name|OPERBOXSIZE
index|]
decl_stmt|;
specifier|register
name|D
operator|,
name|E
operator|,
name|F
operator|,
name|I
expr_stmt|;
name|F
operator|=
operator|*
name|iline
operator|++
expr_stmt|;
if|if
condition|(
operator|(
name|F
operator|==
literal|'.'
operator|)
operator|&&
operator|(
name|digit
argument_list|(
operator|*
name|iline
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|D
operator|=
operator|(
name|int
operator|)
operator|*
name|iline
operator|++
expr_stmt|;
name|E
operator|=
operator|(
name|int
operator|)
operator|*
name|iline
operator|++
expr_stmt|;
for|for
control|(
name|I
operator|=
literal|0
init|;
name|I
operator|<=
name|OPERBOXSIZE
condition|;
name|I
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|D
operator|==
operator|(
name|charconv
index|[
name|I
index|]
operator|.
name|letters
index|[
literal|0
index|]
operator|)
operator|)
operator|&&
operator|(
name|E
operator|==
operator|(
name|charconv
index|[
name|I
index|]
operator|.
name|letters
index|[
literal|1
index|]
operator|)
operator|)
condition|)
block|{
name|F
operator|=
name|charconv
index|[
name|I
index|]
operator|.
name|returnchar
expr_stmt|;
goto|goto
name|out
goto|;
block|}
block|}
operator|--
name|iline
expr_stmt|;
operator|--
name|iline
expr_stmt|;
block|}
name|out
label|:
return|return
operator|(
name|F
operator|)
return|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* eventually this should be replaces with arrays that hae a better	*/
end_comment

begin_comment
comment|/*	method of selecting and returning the lexical value, but	*/
end_comment

begin_comment
comment|/*	for now, this is a quick implementation 			*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*	use char as subscript from ascii - get apl character hopefully  */
end_comment

begin_comment
comment|/*	for character conversion from ascii to apl char set ---		*/
end_comment

begin_comment
comment|/* see files write2.c and write3.c for more recent version 		*/
end_comment

begin_decl_stmt
name|struct
name|asoperbox
name|charconv
index|[
name|OPERBOXSIZE
index|]
init|=
block|{
comment|/* ascii mnemonic ( from HP  APL ascii char mnemonics and 		*/
comment|/*	equivalent apl character value.					*/
comment|/* 	all are two lowercase letters preceeded by a dot.		*/
comment|/*	letters for identifiers are lowercase or uppercase		*/
comment|/*	lowercase corresponding to apl uppercase and			*/
comment|/*	uppercase corresponding to apl underscored letters.		*/
literal|"sg"
block|,
comment|/* unary SGN		*/
literal|'@'
block|,
literal|"le"
block|,
comment|/* less than or equal	*/
literal|'$'
block|,
literal|"ge"
block|,
comment|/* greater than or equal*/
literal|'^'
block|,
literal|"ne"
block|,
comment|/* not equal		*/
literal|'*'
block|,
literal|"om"
block|,
comment|/* omega ( not used )	*/
literal|'W'
block|,
literal|"ep"
block|,
comment|/* epsilon		*/
literal|'E'
block|,
literal|"rh"
block|,
comment|/* shape (rho)		*/
literal|'R'
block|,
literal|"nt"
block|,
comment|/* not ( also '~' )	*/
literal|'T'
block|,
literal|"tk"
block|,
comment|/* take ( also '^' )	*/
literal|'Y'
block|,
literal|"dr"
block|,
comment|/* drop			*/
literal|'U'
block|,
literal|"it"
block|,
comment|/* iota			*/
literal|'I'
block|,
literal|"ci"
block|,
comment|/* circular function	*/
literal|'O'
block|,
literal|"al"
block|,
comment|/* alpha ( not used )	*/
literal|'A'
block|,
literal|"cl"
block|,
comment|/* maximum ( ceiling )  */
literal|'S'
block|,
literal|"fl"
block|,
comment|/* minimum ( floor )	*/
literal|'D'
block|,
literal|"dl"
block|,
comment|/* del ( not used )	*/
literal|'G'
block|,
literal|"de"
block|,
comment|/* upside down del	*/
literal|'H'
block|,
literal|"jt"
block|,
comment|/* small circle ( null )*/
literal|'J'
block|,
literal|"qd"
block|,
comment|/* quad			*/
literal|'L'
block|,
literal|"ss"
block|,
comment|/* right U ( not used )	*/
literal|'Z'
block|,
literal|"sc"
block|,
comment|/* left U ( not used )	*/
literal|'X'
block|,
literal|"si"
block|,
comment|/* Down U		*/
literal|'C'
block|,
literal|"su"
block|,
comment|/* U ( not used )	*/
literal|'V'
block|,
literal|"[^"
block|,
comment|/* upside-down del	*/
literal|'H'
block|,
literal|"bv"
block|,
comment|/* decode ( base )	*/
literal|'B'
block|,
literal|"rp"
block|,
comment|/* encode ( rep )	*/
literal|'N'
block|,
literal|"br"
block|,
comment|/* residue ( mod )	*/
literal|'M'
block|,
literal|"sp"
block|,
comment|/* assignment		*/
literal|'['
block|,
literal|"go"
block|,
comment|/* goto			*/
literal|']'
block|,
literal|"or"
block|,
comment|/* or			*/
literal|'('
block|,
literal|"nn"
block|,
comment|/* nand			*/
literal|0205
block|,
literal|"nr"
block|,
comment|/* nor			*/
literal|0206
block|,
literal|"lg"
block|,
comment|/* log			*/
literal|0207
block|,
literal|"rv"
block|,
comment|/* reversal		*/
literal|0217
block|,
literal|"tr"
block|,
comment|/* transpose		*/
literal|0212
block|,
literal|"rb"
block|,
comment|/* reverse bar		*/
literal|0214
block|,
literal|"cb"
block|,
comment|/* comma bar ( not used)*/
literal|0
block|,
literal|"sb"
block|,
comment|/* slash bar		*/
literal|0200
block|,
literal|"bb"
block|,
comment|/* blackslash bar	*/
literal|0201
block|,
literal|"gu"
block|,
comment|/* grade up		*/
literal|0215
block|,
literal|"gd"
block|,
comment|/* grade down		*/
literal|0216
block|,
literal|"qq"
block|,
comment|/* quote quad		*/
literal|0202
block|,
literal|"dm"
block|,
comment|/* domino		*/
literal|0214
block|,
literal|"lm"
block|,
comment|/* lamp			*/
literal|0204
block|,
literal|"ib"
block|,
comment|/* i - beam		*/
literal|0213
block|,
literal|"ex"
block|,
comment|/* execute ( not used )	*/
literal|0
block|,
literal|"fr"
block|,
comment|/* format( not used )	*/
literal|0
block|,
literal|"di"
block|,
comment|/* diamond ( not used )	*/
literal|0
block|,
literal|"ot"
block|,
comment|/* out ( not used ) 	*/
literal|0
block|,
literal|"ld"
block|,
comment|/* locked del (not used)*/
literal|0
block|,
literal|"[a"
block|,
comment|/* alias for 'A'	*/
literal|0220
block|,
literal|"[b"
block|,
comment|/* alias for 'B'	*/
literal|0221
block|,
literal|"[c"
block|,
comment|/* alias for 'C'	*/
literal|0222
block|,
literal|"[d"
block|,
comment|/* alias for 'D'	*/
literal|0223
block|,
literal|"[e"
block|,
comment|/* alias for 'E'	*/
literal|0224
block|,
literal|"[f"
block|,
comment|/* alias for 'F'	*/
literal|0225
block|,
literal|"[g"
block|,
comment|/* alias for 'G'	*/
literal|0226
block|,
literal|"[h"
block|,
comment|/* alias for 'H'	*/
literal|0227
block|,
literal|"[i"
block|,
comment|/* alias for 'I'	*/
literal|0230
block|,
literal|"[j"
block|,
comment|/* alias for 'J'	*/
literal|0231
block|,
literal|"[k"
block|,
comment|/* alias for 'K'	*/
literal|0232
block|,
literal|"[l"
block|,
comment|/* alias for 'L'	*/
literal|0233
block|,
literal|"[m"
block|,
comment|/* alias for 'M'	*/
literal|0234
block|,
literal|"[n"
block|,
comment|/* alias for 'N'	*/
literal|0235
block|,
literal|"[o"
block|,
comment|/* alias for 'O'	*/
literal|0236
block|,
literal|"[p"
block|,
comment|/* alias for 'P'	*/
literal|0237
block|,
literal|"[q"
block|,
comment|/* alias for 'Q'	*/
literal|0240
block|,
literal|"[r"
block|,
comment|/* alias for 'R'	*/
literal|0241
block|,
literal|"[s"
block|,
comment|/* alias for 'S'	*/
literal|0242
block|,
literal|"[t"
block|,
comment|/* alias for 'T'	*/
literal|0243
block|,
literal|"[u"
block|,
comment|/* alias for 'U'	*/
literal|0244
block|,
literal|"[v"
block|,
comment|/* alias for 'V'	*/
literal|0245
block|,
literal|"[w"
block|,
comment|/* alias for 'W'	*/
literal|0246
block|,
literal|"[x"
block|,
comment|/* alias for 'X'	*/
literal|0247
block|,
literal|"[y"
block|,
comment|/* alias for 'Y'	*/
literal|0250
block|,
literal|"[z"
block|,
comment|/* alias for 'Z'	*/
literal|0251
block|}
decl_stmt|;
end_decl_stmt

end_unit

