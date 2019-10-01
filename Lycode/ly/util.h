#pragma once

template <class T> void swap(T& _Elem1, T& _Elem2) { T temp = _Elem1; _Elem1 = _Elem2; _Elem2 = temp; }
template <class T> void reverse(T& _Cont) { std::reverse(std::begin(_Cont), std::end(_Cont)); }
template <class T> std::string string(T& _Cont) { return std::string(std::begin(_Cont), std::end(_Cont)); }


#define member_op(o, m)       this->##m ##o rhs.##m
#define member_op_s(o, m, mb) this->##mb ##o ##m

#define make_op(o, r, s, a) make_op_##r##_##s(##o, ##a)
#define make_op_false_false(o,a) inline void	operator ##o##a(vec2<T>& rhs) { member_op(##o=, x); member_op(##o=, y); }
#define make_op_true_false(o,a)  inline vec2<T> operator ##o   (vec2<T>& rhs) { return vec2<T>(member_op(##o, x), member_op(##o, y)); }
#define make_op_false_true(o,a)  inline void	operator ##o##a(T& rhs)		  { member_op_s(##o=, rhs, x); member_op_s(##o=, rhs, y); }
#define make_op_true_true(o,a)   inline vec2<T> operator ##o   (T& rhs)		  { return vec2<T>(member_op_s(##o, rhs, x); member_op_s(##o, rhs, y)); }

#define make_ops(r, s) \
	make_op(+, ##r, ##s, ) \
	make_op(-, ##r, ##s, ) \
	make_op(*, ##r, ##s, ) \
	make_op(/, ##r, ##s, ) \
	make_op(+, ##r, ##s,=) \
	make_op(-, ##r, ##s,=) \
	make_op(*, ##r, ##s,=) \
	make_op(/, ##r, ##s,=)


template <class T> struct vec2 {
	T x, y;
	vec2(T x, T y) { this->x = x; this->y = y; }
	vec2(void) {}

	operator std::string() const { return "[" + std::to_string(this->x) + ", " + std::to_string(this->y) + "]"; }

	make_ops(false, false)
	make_ops(false, true )

	inline bool operator==(const vec2<T>& rhs){ return (this->x == rhs.x) && (this->y == rhs.y); }
	inline bool operator!=(const vec2<T>& rhs){ return (this->x != rhs.x) ? true : (this->y != rhs.y) ? true : false; }

	template <class T> inline static void swap(vec2<T>& rhs) { T temp = rhs.x; rhs.x = rhs.y; rhs.y = temp; }

};

// Template Typedefs
typedef vec2<int>			vec2i;
typedef vec2<double>		vec2d;
typedef vec2<float>			vec2f;
typedef vec2<long>			vec2l;
typedef vec2<unsigned long> vec2ul;
typedef vec2<unsigned int>	vec2u;

std::ostream& operator<<(std::ostream& o, const vec2i& v) { return o << "[" << v.x << ", " << v.y << "]"; }