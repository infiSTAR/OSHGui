#ifndef OSHGUI_CONTROL_HPP_
#define OSHGUI_CONTROL_HPP_

#include <vector>
#include <algorithm>

#include "../Exports.hpp"

#include "..\Application.hpp"

#include "..\Drawing\Point.hpp"
#include "..\Drawing\Size.hpp"
#include "..\Drawing\Rectangle.hpp"
#include "..\Drawing\IRenderer.hpp"

#include "..\Misc\Strings.hpp"
#include "..\Misc\Any.hpp"

#include "..\Event\KeyboardEvent.hpp"
#include "..\Event\MouseEvent.hpp"
#include "..\Event\EventHandler.hpp"
#include "..\Event\KeyEventArgs.hpp"
#include "..\Event\KeyPressEventArgs.hpp"
#include "..\Event\MouseEventArgs.hpp"

#include "..\Cursor\Cursors.hpp"

namespace OSHGui
{
	/**
	 * Enum �ber die Arten von Steuerelementen.
	 */
	enum CONTROL_TYPE
	{
		CONTROL_ROOT,
		CONTROL_PANEL,
		CONTROL_FORM,
		CONTROL_GROUPBOX,
		CONTROL_LABEL,
		CONTROL_LINKLABEL,
		CONTROL_BUTTON,
		CONTROL_CHECKBOX,
		CONTROL_RADIOBUTTON,
		CONTROL_SCROLLBAR,
		CONTROL_LISTBOX,
		CONTROL_PROGRESSBAR,
		CONTROL_TRACKBAR,
		CONTROL_COMBOBOX,
		CONTROL_TEXTBOX,
		CONTROL_TIMER,
		CONTROL_TABCONTROL,
		CONTROL_TABPAGE,
		CONTROL_PICTUREBOX,
		CONTROL_COLORPICKER,
		CONTROL_COLORBAR
	};
	
	class Control;
	
	/**
	 * Tritt auf, wenn sich der Wert der SelectedIndex-Eigenschaft �ndert.
	 */
	typedef EventHandler<void(Control*)> SelectedIndexChangedEvent;
	/**
	 * Tritt auf, wenn sich der Wert der Color-Eigenschaft �ndert.
	 */
	typedef EventHandler<void(Control*)> ColorChangeEvent;
	/**
	 * Tritt auf, wenn sich der Wert der Checked-Eigenschaft �ndert.
	 */
	typedef EventHandler<void(Control*)> CheckedChangedEvent;
	/**
	 * Tritt auf, wenn sich der Wert der Text-Eigenschaft �ndert.
	 */
	typedef EventHandler<void(Control*)> TextChangedEvent;
	/**
	 * Tritt auf, wenn das angegebene Intervall verstrichen ist.
	 */
	typedef EventHandler<void(Control*)> TickEvent;
	/**
	 * Tritt auf, wenn der TrackBar-Schieberegler verschoben wird.
	 */
	typedef EventHandler<void(Control*)> ScrollEvent;
	/**
	 * Tritt auf, wenn eine Taste gedr�ckt wird.
	 */
	typedef EventHandler<void(Control*, const KeyEventArgs&)> KeyDownEvent;
	/**
	 * Tritt auf, wenn das Steuerelement fokusiert ist und eine Taste gedr�ckt gehalten wird.
	 */
	typedef EventHandler<void(Control*, const KeyPressEventArgs&)> KeyPressEvent;
	/**
	 * Tritt auf, wenn eine Taste losgelassen wird.
	 */
	typedef EventHandler<void(Control*, const KeyEventArgs&)> KeyUpEvent;
	/**
	 * Tritt auf, wenn auf das Steuerelement geklickt wurde.
	 */
	typedef EventHandler<void(Control*)> ClickEvent;
	/**
	 * Tritt auf, wenn mit der Maus auf das Steuerelement geklickt wurde.
	 */
	typedef EventHandler<void(Control*, const MouseEventArgs&)> MouseClickEvent;
	/**
	 * Tritt auf, wenn sich der Mauszeiger �ber dem Steuerlement befindet und eine Maustaste gedr�ckt wurde.
	 */
	typedef EventHandler<void(Control*, const MouseEventArgs&)> MouseDownEvent;
	/**
	 * Tritt auf, wenn der Mauszeiger �ber das Steuerlement bewegt wird.
	 */
	typedef EventHandler<void(Control*, const MouseEventArgs&)> MouseMoveEvent;
	/**
	 * Tritt auf, wenn sich der Mauszeiger �ber dem Steuerlement befindet und eine Maustaste losgelassen wurde.
	 */
	typedef EventHandler<void(Control*, const MouseEventArgs&)> MouseUpEvent;
	/**
	 * Tritt auf, wenn die Maus in den Bereich des Steuerlements bewegt wird.
	 */
	typedef EventHandler<void(Control*)> MouseEnterEvent;
	/**
	 * Tritt auf, wenn die Maus den Bereich des Steuerlements verl�sst.
	 */
	typedef EventHandler<void(Control*)> MouseLeaveEvent;
	/**
	 * Tritt auf, wenn das Steuerelement zu dem aktiven Steuerelement auf dem Formular wird.
	 */
	typedef EventHandler<void(Control*)> FocusInEvent;
	/**
	 * Tritt auf, wenn das Steuerelement nicht mehr das aktive Steuerelement auf dem Formular ist.
	 */
	typedef EventHandler<void(Control*)> FocusOutEvent;

	/**
	 * Definiert die Basisklasse f�r Steuerelemente, die Komponenten mit visueller Darstellung sind.
	 */
	class OSHGUI_EXPORT Control
	{
	public:
		virtual ~Control();
		
		/**
		 * Ruft den CONTROL_TYPE des Steuerelemts ab.
		 *
		 * @return der Typ
		 */
		CONTROL_TYPE GetType() const;
		
		/**
		 * Legt fest, ob das Steuerlement auf Benutzerinteraktionen reagieren kann.
		 *
		 * @param enabled
		 */
		void SetEnabled(bool enabled);
		/**
		 * Ruft ab, ob das Steuerlement auf Benutzerinteraktionen reagieren kann.
		 *
		 * @return enabled
		 */
		bool GetEnabled() const;
		/**
		 * Legt fest, ob das Steuerelement und alle untergeordneten Steuerelemente
		 * angezeigt werden.
		 *
		 * @param visible
		 */
		void SetVisible(bool visible);
		/**
		 * Ruft ab, ob das Steuerelement und alle untergeordneten Steuerelemente
		 * angezeigt werden.
		 *
		 * @return visible
		 */
		bool GetVisible() const;
		
		/**
		 * Legt fest, ob die Gr��e des Steuerelements automatisch an dessen Inhalt anpasst.
		 *
		 * @param autoSize
		 */
		virtual void SetAutoSize(bool autoSize);
		/**
		 * Ruft ab, ob die Gr��e des Steuerelements automatisch an dessen Inhalt anpasst.
		 *
		 * @return autoSize
		 */
		virtual bool GetAutoSize() const;
		/**
		 * Legt die Gr��e und Position des Steuerelements relativ zum �bergeordneten
		 * Steuerelement fest.
		 *
		 * @param bounds
		 */
		virtual void SetBounds(Drawing::Rectangle &bounds);
		/**
		 * Legt die Gr��e und Position des Steuerelements relativ zum �bergeordneten
		 * Steuerelement fest.
		 *
		 * @param location
		 * @param size
		 */
		virtual void SetBounds(Drawing::Point location, Drawing::Size &size);
		/**
		 * Legt die Gr��e und Position des Steuerelements relativ zum �bergeordneten
		 * Steuerelement fest.
		 *
		 * @param x
		 * @param y
		 * @param w
		 * @param h
		 */
		virtual void SetBounds(int x, int y, int w, int h);
		/**
		 * Ruft die Gr��e und Position des Steuerelements relativ zum �bergeordneten
		 * Steuerelement ab.
		 *
		 * @return bounds
		 */
		virtual const Drawing::Rectangle GetBounds() const;
		/**
		 * Legt die Koordinaten der linken oberen Ecke des Steuerelements relativ zur
		 * linken oberen Ecke des Containers fest.
		 *
		 * @param location
		 */
		virtual void SetLocation(const Drawing::Point &location);
		/**
		 * Legt die Koordinaten der linken oberen Ecke des Steuerelements relativ zur
		 * linken oberen Ecke des Containers fest.
		 *
		 * @param x
		 * @param y
		 */
		virtual void SetLocation(int x, int y);
		/**
		 * Ruft die Koordinaten der linken oberen Ecke des Steuerelements relativ zur
		 * linken oberen Ecke des Containers ab.
		 *
		 * @return location
		 */
		virtual const Drawing::Point GetLocation() const;
		/**
		 * Legt die H�he und Breite des Steuerelements fest.
		 *
		 * @param size
		 */
		virtual void SetSize(const Drawing::Size &size);
		/**
		 * Legt die H�he und Breite des Steuerelements fest.
		 *
		 * @param width
		 * @param height
		 */
		virtual void SetSize(int width, int height);
		/**
		 * Ruft die H�he und Breite des Steuerelements ab.
		 *
		 * @return size
		 */
		virtual const Drawing::Size GetSize() const;
		/**
		 * Ruft den Abstand zwischen dem linken Rand des Steuerelements und dem linken
		 * Rand des Clientbereichs des zugeh�rigen Containers ab.
		 *
		 * @return left
		 */
		virtual int GetLeft() const;
		/**
		 * Ruft den Abstand zwischen dem oberen Rand des Steuerelements und dem oberen
		 * Rand des Clientbereichs des zugeh�rigen Containers ab.
		 *
		 * @return top
		 */
		virtual int GetTop() const;
		/**
		 * Ruft den Abstand zwischen dem rechten Rand des Steuerelements und dem linken
		 * Rand des Clientbereichs des zugeh�rigen Containers ab.
		 *
		 * @return right
		 */
		virtual int GetRight() const;
		/**
		 * Ruft den Abstand zwischen dem unteren Rand des Steuerelements und dem oberen
		 * Rand des Clientbereichs des zugeh�rigen Containers ab.
		 *
		 * @return bottom
		 */
		virtual int GetBottom() const;
		/**
		 * Ruft die Breite des Steuerelements ab.
		 *
		 * @return width
		 */
		virtual int GetWidth() const;
		/**
		 * Ruft die H�he des Steuerelements ab.
		 *
		 * @return height
		 */
		virtual int GetHeight() const;
		/**
		 * Legt die mit dem Steuerelement verkn�pften benutzerdefinierten Daten fest.
		 *
		 * @param tag
		 */
		void SetTag(Misc::Any &tag);
		/**
		 * Ruft die mit dem Steuerelement verkn�pften benutzerdefinierten Daten ab.
		 *
		 * @return tag
		 */
		Misc::Any& GetTag();
		/**
		 * Legt den zum Identifizieren des Steuerelements verwendeten Namen fest.
		 *
		 * @param name
		 */
		void SetName(const Misc::UnicodeString &name);
		/**
		 * Ruft den zum Identifizieren des Steuerelements verwendeten Namen ab.
		 *
		 * @return name
		 */
		const Misc::UnicodeString& GetName() const;
		/**
		 * Legt die Schriftart des Texts im Steuerelement fest.
		 *
		 * @param font
		 */
		void SetFont(const std::shared_ptr<Drawing::IFont> &font);
		/**
		 * Ruft die Schriftart des Texts im Steuerelement ab.
		 *
		 * @return font
		 */
		const std::shared_ptr<Drawing::IFont> GetFont() const;
		void SetCursor(const std::shared_ptr<Cursor> &cursor);
		const std::shared_ptr<Cursor> GetCursor() const;
		/**
		 * Legt die Fordergrundfarbe des Steuerelements fest.
		 *
		 * @param color
		 */
		void SetForeColor(Drawing::Color color);
		/**
		 * Ruft die Fordergrundfarbe des Steuerelements ab.
		 *
		 * @return color
		 */
		const Drawing::Color& GetForeColor() const;
		/**
		 * Legt die Hintergrundfarbe des Steuerelements fest.
		 *
		 * @param color
		 */
		void SetBackColor(Drawing::Color color);
		/**
		 * Ruft die Hintergrundfarbe des Steuerelements ab.
		 *
		 * @return color
		 */
		const Drawing::Color& GetBackColor() const;
		/**
		 * Legt die Farbe f�r das fokusierte Steuerelement fest.
		 *
		 * @param color
		 */
		void SetMouseOverFocusColor(Drawing::Color color);
		/**
		 * Ruft die Farbe f�r das fokusierte Steuerelement ab.
		 *
		 * @return color
		 */
		const Drawing::Color& GetMouseOverFocusColor() const;
		/**
		 * Ruft das ClickEvent f�r das Steuerelement ab.
		 *
		 * @return clickEvent
		 */
		ClickEvent& GetClickEvent();
		/**
		 * Ruft das MouseClickEvent f�r das Steuerelement ab.
		 *
		 * @return mouseClickEvent
		 */
		MouseClickEvent& GetMouseClickEvent();
		/**
		 * Ruft das MouseClickEvent f�r das Steuerelement ab.
		 *
		 * @return mouseClickEvent
		 */
		MouseDownEvent& GetMouseDownEvent();
		/**
		 * Ruft das MouseClickEvent f�r das Steuerelement ab.
		 *
		 * @return mouseClickEvent
		 */
		MouseMoveEvent& GetMouseMoveEvent();
		/**
		 * Ruft das MouseClickEvent f�r das Steuerelement ab.
		 *
		 * @return mouseClickEvent
		 */
		MouseUpEvent& GetMouseUpEvent();
		/**
		 * Ruft das MouseEnterEvent f�r das Steuerelement ab.
		 *
		 * @return mouseEnterEvent
		 */
		MouseEnterEvent& GetMouseEnterEvent();
		/**
		 * Ruft das MouseLeaveEvent f�r das Steuerelement ab.
		 *
		 * @return mouseLeaveEvent
		 */
		MouseLeaveEvent& GetMouseLeaveEvent();
		/**
		 * Ruft das FocusInEvent f�r das Steuerelement ab.
		 *
		 * @return forcusInEvent
		 */
		FocusInEvent& GetFocusInEvent();
		/**
		 * Ruft das FocusOutEvent f�r das Steuerelement ab.
		 *
		 * @return forcusOutEvent
		 */
		FocusOutEvent& GetFocusOutEvent();

		/**
		 * �berpr�ft, ob das Steuerelement den Fokus �bernehmen kann.
		 *
		 * @return ja / nein
		 */
		virtual bool CanHaveFocus() const;
		/**
		 * �berpr�ft, ob sich der Punkt innerhalb des Steuerelements befindet.
		 *
		 * @param point
		 * @return ja / nein
		 */
		virtual bool ContainsPoint(const Drawing::Point &point) const;
		/**
		 * Veranlasst das Steuerelemt seine interne Struktur neu zu berechnen.
		 * Wird au�erdem f�r alle Kindelemente aufgerufen.
		 *
		 * Sollte nicht vom Benutzer aufgerufen werden!
		 */
		virtual void Invalidate();
		/**
		 * Ruft Invalidate f�r alle Kindelemente auf.
		 *
		 * Sollte nicht vom Benutzer aufgerufen werden!
		 */
		void InvalidateChildren();

		/**
		 * F�gt ein untergeordnetes Steuerelement hinzu.
		 *
		 * @param control
		 */
		void AddControl(Control *control);
		/**
		 * Rechnet die Position des angegeben Bildschirmpunkts in Clientkoordinaten um.
		 *
		 * @param point
		 * @return der neue Punkt
		 */
		virtual const Drawing::Point PointToClient(const Drawing::Point &point) const;
		/**
		 * Rechnet die Position des angegeben Clientpunkts in Bildschirmkoordinaten um.
		 *
		 * @param point
		 * @return der neue Punkt
		 */
		virtual const Drawing::Point PointToScreen(const Drawing::Point &point) const;
		/**
		 * Ruft das untergeordnete Steuerelement ab, das sich an den angegebenen
		 * Koordinaten befindet.
		 *
		 * @param point
		 * @return 0, falls sich dort kein Steuerelement befindet
		 */
		Control* GetChildAtPoint(const Drawing::Point &point) const;
		/**
		 * Ruft das untergeordnete Steuerelement mit dem entsprechenden Namen ab.
		 *
		 * @param name
		 * @return 0, falls kein Steuerelement mit diesem Namen existiert
		 */
		Control* GetChildByName(const Misc::UnicodeString &name) const;
		/**
		 * Legt das �bergebene Control als fokusiert fest.
		 *
		 * @param control
		 */
		void RequestFocus(Control *control);
		/**
		 * L�st den Fokus.
		 */
		void ClearFocus();
		
		/**
		 * Verarbeitet ein Event und gibt es wenn n�tig an Kindelemente weiter.
		 *
		 * @param event
		 * @return NextEventTypes
		 */
		virtual IEvent::NextEventTypes ProcessEvent(IEvent *event);
		/**
		 * Wird von ProcessEvent verwendet, um Kindelemete Events verarbeiten zu lassen.
		 *
		 * @param event
		 * @return NextEventTypes
		 */
		IEvent::NextEventTypes ChildProcessEvent(IEvent *event);
		/**
		 * Zeichnet das Steuerelement mithilfe des �bergebenen IRenderers.
		 *
		 * @param renderer
		 */
		virtual void Render(Drawing::IRenderer *renderer);
		
		/**
		 * Gibt das �bergeordnete Steuerelement zur�ck.
		 *
		 * @return parent
		 */
		Control* GetParent() const;
		/**
		 * Gibt eine Liste der untergeordneten Steuerelemente zur�ck.
		 *
		 * @return parent
		 */
		const std::vector<Control*>& GetControls() const;	
	
	protected:
		/**
		 * Konstruktor der Klasse.
		 *
		 * @param parent das Elternsteuerelement
		 */
		Control(Control *parent = 0);
	
		IEvent::NextEventTypes ContainerProcessEvent(IEvent *event);

		virtual void SetFocus(bool focus);
		virtual void SetMouseOver(bool mouseOver);
		
		CONTROL_TYPE type;
		
		Misc::UnicodeString name;
	
		bool enabled,
			 needRepaint,
			 visible,
			 mouseOver,
			 hasFocus,
			 autoSize;
			 
		Misc::Any tag;
		
		Drawing::Rectangle bounds,
						   clientArea;
		
		ClickEvent clickEvent;
		MouseClickEvent mouseClickEvent;
		MouseDownEvent mouseDownEvent;
		MouseMoveEvent mouseMoveEvent;
		MouseUpEvent mouseUpEvent;
		MouseEnterEvent mouseEnterEvent;
		MouseLeaveEvent mouseLeaveEvent;
		FocusInEvent focusInEvent;
		FocusOutEvent focusOutEvent;
		
		Drawing::Color foreColor,
					   backColor,
					   mouseOverFocusColor;
		
		std::shared_ptr<Drawing::IFont> font;
		std::shared_ptr<Cursor> cursor;

		Control *parent;

		std::vector<Control*> controls;

		Control *focusControl,
				*mouseOverControl;

	private:
		//copying prohibited
		Control(const Control&);
		void operator = (const Control&);
	};
}

#endif