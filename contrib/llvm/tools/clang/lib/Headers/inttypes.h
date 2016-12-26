begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- inttypes.h - Standard header for integer printf macros ----------===*\  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  * \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_INTTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|__CLANG_INTTYPES_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1800
end_if

begin_error
error|#
directive|error
error|MSVC does not have inttypes.h prior to Visual Studio 2013
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<inttypes.h>
end_empty

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1900
end_if

begin_comment
comment|/* MSVC headers define int32_t as int, but PRIx32 as "lx" instead of "x".  * This triggers format warnings, so fix it up here. */
end_comment

begin_undef
undef|#
directive|undef
name|PRId32
end_undef

begin_undef
undef|#
directive|undef
name|PRIdLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIdFAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIi32
end_undef

begin_undef
undef|#
directive|undef
name|PRIiLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIiFAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIo32
end_undef

begin_undef
undef|#
directive|undef
name|PRIoLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIoFAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIu32
end_undef

begin_undef
undef|#
directive|undef
name|PRIuLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIuFAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIx32
end_undef

begin_undef
undef|#
directive|undef
name|PRIxLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIxFAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIX32
end_undef

begin_undef
undef|#
directive|undef
name|PRIXLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|PRIXFAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNd32
end_undef

begin_undef
undef|#
directive|undef
name|SCNdLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNdFAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNi32
end_undef

begin_undef
undef|#
directive|undef
name|SCNiLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNiFAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNo32
end_undef

begin_undef
undef|#
directive|undef
name|SCNoLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNoFAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNu32
end_undef

begin_undef
undef|#
directive|undef
name|SCNuLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNuFAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNx32
end_undef

begin_undef
undef|#
directive|undef
name|SCNxLEAST32
end_undef

begin_undef
undef|#
directive|undef
name|SCNxFAST32
end_undef

begin_define
define|#
directive|define
name|PRId32
value|"d"
end_define

begin_define
define|#
directive|define
name|PRIdLEAST32
value|"d"
end_define

begin_define
define|#
directive|define
name|PRIdFAST32
value|"d"
end_define

begin_define
define|#
directive|define
name|PRIi32
value|"i"
end_define

begin_define
define|#
directive|define
name|PRIiLEAST32
value|"i"
end_define

begin_define
define|#
directive|define
name|PRIiFAST32
value|"i"
end_define

begin_define
define|#
directive|define
name|PRIo32
value|"o"
end_define

begin_define
define|#
directive|define
name|PRIoLEAST32
value|"o"
end_define

begin_define
define|#
directive|define
name|PRIoFAST32
value|"o"
end_define

begin_define
define|#
directive|define
name|PRIu32
value|"u"
end_define

begin_define
define|#
directive|define
name|PRIuLEAST32
value|"u"
end_define

begin_define
define|#
directive|define
name|PRIuFAST32
value|"u"
end_define

begin_define
define|#
directive|define
name|PRIx32
value|"x"
end_define

begin_define
define|#
directive|define
name|PRIxLEAST32
value|"x"
end_define

begin_define
define|#
directive|define
name|PRIxFAST32
value|"x"
end_define

begin_define
define|#
directive|define
name|PRIX32
value|"X"
end_define

begin_define
define|#
directive|define
name|PRIXLEAST32
value|"X"
end_define

begin_define
define|#
directive|define
name|PRIXFAST32
value|"X"
end_define

begin_define
define|#
directive|define
name|SCNd32
value|"d"
end_define

begin_define
define|#
directive|define
name|SCNdLEAST32
value|"d"
end_define

begin_define
define|#
directive|define
name|SCNdFAST32
value|"d"
end_define

begin_define
define|#
directive|define
name|SCNi32
value|"i"
end_define

begin_define
define|#
directive|define
name|SCNiLEAST32
value|"i"
end_define

begin_define
define|#
directive|define
name|SCNiFAST32
value|"i"
end_define

begin_define
define|#
directive|define
name|SCNo32
value|"o"
end_define

begin_define
define|#
directive|define
name|SCNoLEAST32
value|"o"
end_define

begin_define
define|#
directive|define
name|SCNoFAST32
value|"o"
end_define

begin_define
define|#
directive|define
name|SCNu32
value|"u"
end_define

begin_define
define|#
directive|define
name|SCNuLEAST32
value|"u"
end_define

begin_define
define|#
directive|define
name|SCNuFAST32
value|"u"
end_define

begin_define
define|#
directive|define
name|SCNx32
value|"x"
end_define

begin_define
define|#
directive|define
name|SCNxLEAST32
value|"x"
end_define

begin_define
define|#
directive|define
name|SCNxFAST32
value|"x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CLANG_INTTYPES_H */
end_comment

end_unit

