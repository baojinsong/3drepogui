/**
 *  Copyright (C) 2014 3D Repo Ltd
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef REPOGUI_H
#define REPOGUI_H

#include <QMainWindow>
#include <QGLFormat>

// CORE
#include <repo/repo_controller.h>

// GUI

#include "../../repo/widgets/repo_widget_rendering.h"
#include "../../widgets/repo_mdisubwindow.h"
//------------------------------------------------------------------------------


namespace Ui
{
    class RepoGUI;
}

namespace repo {
namespace gui {


//! Main application window.
class RepoGUI : public QMainWindow
{
    Q_OBJECT

public:

    //! Explicit default constructor
    explicit RepoGUI(
		repo::RepoController *controller,
		QWidget *parent = 0);

    //! Destructor
    ~RepoGUI();

	/**
	* returns controller to library
	* @return instance of RepoController
	*/
	repo::RepoController* getController()
	{
		return controller;
	}

public slots:

    //! Shows about dialog.
    void about();

    //! Creates a new map tiles project.
    void addMapTiles();

    //! Adds a selection tree for a currently active widget.
    void addSelectionTree()
    {  addSelectionTree(getActiveWidget()); }

    //! Adds a selection tree for a given widget.
    void addSelectionTree(
            widgets::RepoRenderingWidget* widget,
            Qt::DockWidgetArea area = Qt::RightDockWidgetArea);


    //! Shows a commit dialog based on currently active 3D window.
    void commit();

	void commit(repo::core::model::RepoScene *scene,
                repo::gui::RepoMdiSubWindow *activeWindow = 0);

    //! Shows a connection dialog and connects to the specified database.
    void connectDB();

    //! Returns a menu with currently available panels.
    QMenu* createPanelsMenu();

    //! Disconnects DB connection and disables repository buttons.
    void disconnectDB();

    //! Shows a dialog confirmation and drops a selected database if agreed.
    void drop();

    //! Federates multiple projects and calls commit.
    void federate();

    //! Fetches head revision from selected DB and branch.
    void fetchHead();

    //! Returns active 3D window, returns null if none and writes to cout.
    widgets::RepoRenderingWidget *getActiveWidget() const;

    //! Returns the scene graph of the active 3D window if any.
    const repo::core::model::RepoScene *getActiveScene() const;

    //! Shows a history dialog for selected repository.
    void history();

    //! Loads a single 3D file asynchronously given a full file path.
    void loadFile(const QString &filePath);

    //! Loads files from a list of URLs.
    void loadFiles(const QList<QUrl> &urls);

    //! Loads files from a list of full file paths.
    void loadFiles(const QStringList &filePaths);

    //! Opens a 3D Diff dialog.
    void open3DDiff();

    //! Opens Access Manager dialog.
    void openAccessManager();

    //! Opens a file dialog.
    void openFile();

    //! Opens metadata manager.
    void openMetadataManager();

    //! Opens settings dialog.
    void openSettings() const;

    //! Opens scene graph view.
    void openSceneGraph() const;

    //! Opens local email client with support email address predefined.
    void openSupportEmail() const;

    void optimizeGraph();

    //! Refreshes currently connected database.
    void refresh();

    //! Opens a GitHub issues webpage in the default web browser.
    void reportIssue() const;

    //! Saves open 3D window as a file.
    void saveAs();

    //! Saves open 3D window as an image file (screenshot).
    void saveScreenshot();

    //! Displays the popup context menu on the repositories widget collection view.
    void showCollectionContextMenuSlot(const QPoint &pos);

    //! Displays the popup context menu on the repositories widget databases view.
    void showDatabaseContextMenu(const QPoint &pos);

    //! Runs startup procedures. E.g. showing connect window if set via settings.
    void startup();

    /*!
     * Toggles fullscreen mode depending on the status of fullscreen menu action.
     * All visual aspects such as menubar, toolbars, dockwidgets etc are hiddden
     * when in a fullscreen mode and shown upon return.
     */
    void toggleFullScreen();

protected :

    //! Saves window geometry (position) and state.
    void closeEvent(QCloseEvent *event);

    //! Triggered when mouse is being dragged and enters the window.
    void dragEnterEvent(QDragEnterEvent *event);

    //! Triggered when the mouse drops the drag event.
    void dropEvent(QDropEvent *event);

    //! F11 and Esc to return from fullscreen mode.
    void keyPressEvent(QKeyEvent *event);

    //! Restores the previously saved geometry and state of the application.
    void restoreSettings();

    //! Stores the current geometry and state of the application.
    void storeSettings();

private:
	//! Controller to talk to the core
	repo::RepoController *controller;

    //! UI var.
    Ui::RepoGUI *ui;
	
    //! Panels menu (dockable widgets and toolbars)
    QMenu *panelsMenu;

    //! Settings geometry label.
    static const QString REPO_SETTINGS_GUI_GEOMETRY;

    //! Settings state label.
    static const QString REPO_SETTINGS_GUI_STATE;

    //! Settings link windows label.
    static const QString REPO_SETTINGS_LINK_WINDOWS;

}; // end class

} // end namespace gui
} // end namespace repo


#endif // REPOGUI_H