#ifndef __OSHGUI_KEY_H__
#define __OSHGUI_KEY_H__

namespace OSHGui
{
	/**
	 * Stellt Tastencodes bereit.
	 */
	class Key
	{
	public:
		/**
		 * Aufz�hlung der Tastencodes
		 */
		enum Keys
		{
			None,
			D0, D1, D2, D3, D4, D5, D6, D7, D8, D9,
			A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			Space, Back,
			Insert, Home, End, Delete, PageUp, PageDown,
			Alt, Control, Shift, Tab,
			Return, Escape,
			Up, Right, Down, Left,
			Divide, Multiply, Substract, Add
		};
	};
}

#endif