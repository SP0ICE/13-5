#include <QApplication>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QDateTime>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Slider Date Example");

    QSlider slider(Qt::Horizontal);
    QLabel label(QDateTime::currentDateTime().toString("dd.MM.yyyy"));

    QVBoxLayout layout;
    layout.addWidget(&slider);
    layout.addWidget(&label);
    window.setLayout(&layout);

    QObject::connect(&slider, &QSlider::valueChanged, [&label](int value) {
        QDateTime date = QDateTime::currentDateTime().addDays(value);
        label.setText(date.toString("dd.MM.yyyy"));
    });

    window.show();

    return app.exec();
}
