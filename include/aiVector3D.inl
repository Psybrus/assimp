/*
---------------------------------------------------------------------------
Open Asset Import Library (ASSIMP)
---------------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team

All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the following 
conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/

/** @file  aiVector3D.inl
 *  @brief Inline implementation of aiVector3D operators
 */
#ifndef AI_VECTOR3D_INL_INC
#define AI_VECTOR3D_INL_INC

#include "aiVector3D.h"

#ifdef __cplusplus

// ------------------------------------------------------------------------------------------------
/** Transformation of a vector by a 3x3 matrix */
inline aiVector3D operator * (const aiMatrix3x3& pMatrix, const aiVector3D& pVector)
{
	aiVector3D res;
	res.x = pMatrix.a1 * pVector.x + pMatrix.a2 * pVector.y + pMatrix.a3 * pVector.z;
	res.y = pMatrix.b1 * pVector.x + pMatrix.b2 * pVector.y + pMatrix.b3 * pVector.z;
	res.z = pMatrix.c1 * pVector.x + pMatrix.c2 * pVector.y + pMatrix.c3 * pVector.z;
	return res;
}

// ------------------------------------------------------------------------------------------------
/** Transformation of a vector by a 4x4 matrix */
inline aiVector3D operator * (const aiMatrix4x4& pMatrix, const aiVector3D& pVector)
{
	aiVector3D res;
	res.x = pMatrix.a1 * pVector.x + pMatrix.a2 * pVector.y + pMatrix.a3 * pVector.z + pMatrix.a4;
	res.y = pMatrix.b1 * pVector.x + pMatrix.b2 * pVector.y + pMatrix.b3 * pVector.z + pMatrix.b4;
	res.z = pMatrix.c1 * pVector.x + pMatrix.c2 * pVector.y + pMatrix.c3 * pVector.z + pMatrix.c4;
	return res;
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE void aiVector3D::Set( float pX, float pY, float pZ) { 
	x = pX; y = pY; z = pZ; 
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE float aiVector3D::SquareLength() const {
	return x*x + y*y + z*z; 
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE float aiVector3D::Length() const {
	return sqrt( SquareLength()); 
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE aiVector3D& aiVector3D::Normalize() { 
	*this /= Length(); return *this;
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE const aiVector3D& aiVector3D::operator += (const aiVector3D& o) {
	x += o.x; y += o.y; z += o.z; return *this; 
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE const aiVector3D& aiVector3D::operator -= (const aiVector3D& o) {
	x -= o.x; y -= o.y; z -= o.z; return *this;
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE const aiVector3D& aiVector3D::operator *= (float f) {
	x *= f; y *= f; z *= f; return *this; 
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE const aiVector3D& aiVector3D::operator /= (float f) {
	x /= f; y /= f; z /= f; return *this; 
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE aiVector3D& aiVector3D::operator *= (const aiMatrix3x3& mat){
	return(*this =  mat * (*this));
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE aiVector3D& aiVector3D::operator *= (const aiMatrix4x4& mat){
	return(*this = mat * (*this));
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE float aiVector3D::operator[](unsigned int i) const {
	return *(&x + i);
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE float& aiVector3D::operator[](unsigned int i) {
	return *(&x + i);
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE bool aiVector3D::operator== (const aiVector3D& other) const {
	return x == other.x && y == other.y && z == other.z;
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE bool aiVector3D::operator!= (const aiVector3D& other) const {
	return x != other.x || y != other.y || z != other.z;
}
// ------------------------------------------------------------------------------------------------
AI_FORCE_INLINE const aiVector3D aiVector3D::SymMul(const aiVector3D& o) {
	return aiVector3D(x*o.x,y*o.y,z*o.z);
}
// ------------------------------------------------------------------------------------------------
// symmetric addition
AI_FORCE_INLINE aiVector3D operator + (const aiVector3D& v1, const aiVector3D& v2)	{
	return aiVector3D( v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
// ------------------------------------------------------------------------------------------------
// symmetric subtraction
AI_FORCE_INLINE aiVector3D operator - (const aiVector3D& v1, const aiVector3D& v2)	{
	return aiVector3D( v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
// ------------------------------------------------------------------------------------------------
// scalar product
AI_FORCE_INLINE float operator * (const aiVector3D& v1, const aiVector3D& v2)	{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}
// ------------------------------------------------------------------------------------------------
// scalar multiplication
AI_FORCE_INLINE aiVector3D operator * ( float f, const aiVector3D& v)	{
	return aiVector3D( f*v.x, f*v.y, f*v.z);
}
// ------------------------------------------------------------------------------------------------
// and the other way around
AI_FORCE_INLINE  aiVector3D operator * ( const aiVector3D& v, float f)	{
	return aiVector3D( f*v.x, f*v.y, f*v.z);
}
// ------------------------------------------------------------------------------------------------
// scalar division
AI_FORCE_INLINE  aiVector3D operator / ( const aiVector3D& v, float f)	{
	return v * (1/f);
}
// ------------------------------------------------------------------------------------------------
// vector division
AI_FORCE_INLINE  aiVector3D operator / ( const aiVector3D& v, const aiVector3D& v2)	{
	return aiVector3D(v.x / v2.x,v.y / v2.y,v.z / v2.z);
}
// ------------------------------------------------------------------------------------------------
// cross product
AI_FORCE_INLINE  aiVector3D operator ^ ( const aiVector3D& v1, const aiVector3D& v2)	{
	return aiVector3D( v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}
// ------------------------------------------------------------------------------------------------
// vector inversion
AI_FORCE_INLINE  aiVector3D operator - ( const aiVector3D& v)	{
	return aiVector3D( -v.x, -v.y, -v.z);
}

#ifdef ASSIMP_INTERNAL_BUILD
namespace std {

	// std::min for aiVector3D
	inline ::aiVector3D min (const ::aiVector3D& a, const ::aiVector3D& b)	{
		return ::aiVector3D (min(a.x,b.x),min(a.y,b.y),min(a.z,b.z));
	}

	// std::max for aiVector3D
	inline ::aiVector3D max (const ::aiVector3D& a, const ::aiVector3D& b)	{
		return ::aiVector3D (max(a.x,b.x),max(a.y,b.y),max(a.z,b.z));
	}

} // end namespace std
#endif // !! ASSIMP_INTERNAL_BUILD

#endif // __cplusplus
#endif // AI_VECTOR3D_INL_INC
