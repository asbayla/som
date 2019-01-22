#ifndef QtObjectVisitor_HPP
    #define QtObjectVisitor_HPP

    #include <QtCore/QString>
    #include <QtCore/QVariant>

    /**
     * \brief QtObjectVisitor formats the Qt QVariant data for debugging purposes.
     */
    class QtObjectVisitor
    {
    public:
        /**
         * Constructs a formatter.
         */
        QtObjectVisitor();

        /**
         * Returns the the given @p value formatted as string.
         */
        QString asString(const QVariant &value) const;

        void traverse(const QVariant& value, QString& out) const;
    };

    #endif
