#ifndef CANVASHANDLER_H
#define CANVASHANDLER_H

#include <memory>

#include <QObject>
#include <QUrl>


class ProcessingEngine;
class QVTKFramebufferObjectItem;

class CanvasHandler : public QObject
{
	Q_OBJECT

	Q_PROPERTY(bool showFileDialog MEMBER m_showFileDialog NOTIFY showFileDialogChanged)

public:
	CanvasHandler(int argc, char **argv);

	Q_INVOKABLE void openModel(QUrl path);

	Q_INVOKABLE void mousePressEvent(int button, int mouseX, int mouseY);
	Q_INVOKABLE void mouseMoveEvent(int button, int mouseX, int mouseY);
	Q_INVOKABLE void mouseReleaseEvent(int button, int mouseX, int mouseY);

	double getSelectedModelPositionX();
	double getSelectedModelPositionY();

public slots:
	void startApplication();

signals:
	void selectedModelPositionXChanged();
	void selectedModelPositionYChanged();

	void showFileDialogChanged();

private:
	void closeApplication();
	bool isModelExtensionValid(QUrl modelPath);

	std::shared_ptr<ProcessingEngine> m_processingEngine;
	QVTKFramebufferObjectItem *m_vtkFboItem = nullptr;

	double m_previousWorldX = 0;
	double m_previousWorldY = 0;
	bool m_draggingMouse = false;
	bool m_showFileDialog = false;
};

#endif // CANVASHANDLER_H